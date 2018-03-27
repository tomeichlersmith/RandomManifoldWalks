
#include "../MOSEY/MOSEY.hpp"

#include <string> //Processing inputs
#include <sstream> //Making filepath
#include <iostream>
#include <fstream>

/**
 * Description of argv[] array for inputs (default value)
 * argv[0] name of program (./run/PlaneWalk)
 * argv[1] the inner radius of the escape region (1) - set to zero to have no inner circle
 * argv[2] the outer radius of the escape region (2)
 * argv[3] number of walks (1)
 * argv[4] length of each step of the walk (0.05)
 * argv[5] maximum walk length (1000)
 * argv[6] name of data storage file (output) - put into data/ directory
 */
int main( int argc , char* argv[] ) {

	//Default Value
	double inner_rad = 1.;
	double outer_rad = 2.;
	int num_walks = 1;
	double steplen = 0.05;
	double max_walk_len = 1000.;
	std::string filename = "output";

	switch( argc ) {
		case 7 : //Go through all settings, breaking before defaults
			filename = static_cast<std::string>(argv[6]);
		case 6 :
			max_walk_len = std::stod( static_cast<std::string>(argv[5]) );
		case 5 :
			steplen = std::stod( static_cast<std::string>(argv[4]) );
		case 4 :
			num_walks = std::stoi( static_cast<std::string>(argv[3]) );
		case 3 :
			outer_rad = std::stod( static_cast<std::string>(argv[2]) );
		case 2 :
			inner_rad = std::stod( static_cast<std::string>(argv[1]) );
		default : //Keep defaults set above
			break;
	}

	MOSEY::Walk walk( MOSEY::Manifold::Plane );
	walk.SetStepLength( steplen );
	std::vector<double> params( 4 , 0. );
	params[0] = inner_rad; //Change inner radius of circle
	params[1] = outer_rad; //Change outer radius of circle
	walk.SetEscapeRegion( &MOSEY::EscapeCheck::CircleRing , params );
	walk.SetMaxWalkLength( max_walk_len );

	std::ofstream outs;
	outs.open( ("Plane/data/"+filename+".csv").c_str() );
	
	if( outs.is_open() ) {

		outs << "R,WalkLen" << std::endl;
		
		//Starting point
		double start_x = 0.;
		if ( inner_rad > 0. ) {
			start_x = 0.5*(outer_rad - inner_rad) + inner_rad;
		}

		for( int i = 0; i < num_walks; i++ ) {
		
			walk.Wander( start_x , 0. );

			walk.Export( outs , MOSEY::ExportType::Radius );

			std::cout << "[" << i << "/" << num_walks << "] completed...\r" << std::flush;

		}

	}
	else {
		std::cout << "ERROR:\tUnable to open Plane/data/" << filename << ".csv" << std::endl;
		exit(1);
	}

	outs.close();

	std::cout << "Number of Simulated Walks that Ended Before Escaping: " << walk.MaxWalkCount() << std::endl;

	char answer;
	std::cout << "Construct summary file from generated data? (y/n) ";
	std::cin >> answer;

	if ( answer == 'y' or answer == 'Y' ) {

		//Output File Declaration
		std::ofstream sum_out;
		sum_out.open( ("Plane/data/"+filename+"_summary.csv").c_str() );

		//Input File Declaration
		std::ifstream data_in;
		data_in.open( ("Plane/data/"+filename+".csv").c_str() );

		//Data Storage Vectors
		// Store data in 1000 bins
		// Data Range from pol_ang to pi ==> Multiply by 2000/(2pi), truncated integer is the index
		std::vector< double > walktotals ( 1000 , 0. ); //Summing walk lengths
		std::vector< int > walkcounts ( 1000 , 0 ); //Counting number of walks

		if ( sum_out.is_open() and data_in.is_open() ) {

			double rad, walklen;
			int rad_index;
			char comma;

			//First line of data_in
			std::string dummy;
			std::getline( data_in , dummy );

			int numwalks = 0;
			std::cout << std::endl;
			while( !data_in.eof() ) {

				data_in >> rad >> comma >> walklen;

				if ( rad < inner_rad ) {
					rad_index = 0;
				}
				else if ( rad > outer_rad ) {
					rad_index = 999;
				}
				else {
					rad_index = static_cast< int >( (rad - inner_rad)*( 1000 / (outer_rad - inner_rad) ) );
				}

				walktotals[ rad_index ] += walklen;
				walkcounts[ rad_index ] ++;

				if ( walklen == 0 ) {
					numwalks++;
					std::cout << "\r" << numwalks;
				}

			} //read data_in
			std::cout << "\rWriting out summary...";
			//Write out data while calculating means

			sum_out << "R,MeanWalkLen" << std::endl;

			double meanwalklen;
			for (unsigned int i = 0; i < 1000; i++) {

				if ( walkcounts[i] > 0 ) {
					//rad is in the middle of the bin
					// reusing the variable rad
					rad = (i+0.5)*(outer_rad - inner_rad)/1000 + inner_rad;

					meanwalklen = walktotals[i]/walkcounts[i];

					sum_out << rad << "," << meanwalklen << std::endl;
				} //if bin has some data in it

			} //loop through all the bins (i)

			std::cout << "\rDONE: Summary Written  " << std::endl;

		} //files connected
		else if ( sum_out.is_open() ) {
			std::cout << "ERROR:\tUnable to open Plane/data/" << filename << ".csv" << std::endl;
		} //data_in problem
		else {
			std::cout << "ERROR:\tUnable to open Plane/data/" << filename << "_summary.csv" << std::endl;
		} //sum_out problem

		sum_out.close();
		data_in.close();

	} //Construct summary file

	return 0;
}
