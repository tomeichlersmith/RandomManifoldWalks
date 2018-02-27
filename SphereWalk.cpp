
#include "MOSEY/MOSEY.hpp"

#include <string> //Processing inputs
#include <sstream> //Making filepath
#include <iostream>
#include <fstream>

/**
 * Description of argv[] array for inputs (default value)
 * argv[0] name of program (./SphereWalk)
 * argv[1] the latitude of the boundary for the escape region around north pole (MOSEY::TWO_PI/8)
 * argv[2] number of walks (1)
 * argv[3] length of each step of the walk (0.05)
 * argv[4] maximum walk length (1000)
 * argv[5] name of data storage file (output) - put into data/ directory
 */
int main( int argc , char* argv[] ) {

	//Default Value
	double pol_ang = MOSEY::TWO_PI/8;
	int num_walks = 1;
	double steplen = 0.05;
	double max_walk_len = 1000.;
	std::string filename = "output";

	switch( argc ) {
		case 6 : //Go through all settings, breaking before defaults
			filename = static_cast<std::string>(argv[5]);
		case 5 :
			max_walk_len = std::stod( static_cast<std::string>(argv[4]) );
		case 4 :
			steplen = std::stod( static_cast<std::string>(argv[3]) );
		case 3 :
			num_walks = std::stoi( static_cast<std::string>(argv[2]) );
		case 2 :
			pol_ang = std::stod( static_cast<std::string>(argv[1]) );
		default : //Keep defaults set above
			break;
	}

	MOSEY::Walk spherewalk( MOSEY::Manifold::Sphere );
	spherewalk.SetStepLength( steplen );
	std::vector<double> params( 3 , 0. );
	params[0] = sin(pol_ang)/(1-cos(pol_ang)); //Change radius of circle to (u,v)-space
	spherewalk.SetEscapeRegion( &MOSEY::EscapeCheck::OutsideCircle , params );
	spherewalk.SetMaxWalkLength( max_walk_len );

	std::ofstream outs;
	outs.open( ("data/"+filename+".csv").c_str() );

	if( outs.is_open() ) {

		outs << "PolAng,WalkLen" << std::endl;

		for( int i = 0; i < num_walks; i++ ) {

			spherewalk.Wander( 0. , 0. );

			spherewalk.Export( outs , MOSEY::ExportType::PolarAng );

			std::cout << "[" << i << "/" << num_walks << "] completed...\r";

		}

	}
	else {
		std::cout << "ERROR:\tUnable to open " << filename << std::endl;
		exit(1);
	}

	outs.close();

	std::cout << "Number of Simulated Walks that Ended Before Escaping: " << spherewalk.MaxWalkCount() << std::endl;

	char answer;
	std::cout << "Construct summary file from generated data? (y/n) ";
	std::cin >> answer;

	if ( answer == 'y' or answer == 'Y' ) {

		//Output File Declaration
		std::ofstream sum_out;
		sum_out.open( ("data/"+filename+"_summary.csv").c_str() );

		//Input File Declaration
		std::ifstream data_in;
		data_in.open( ("data/"+filename+".csv").c_str() );

		//Data Storage Vectors
		// Store data in 1000 bins
		// Data Range from pol_ang to pi ==> Multiply by 2000/(2pi), truncated integer is the index
		std::vector< double > walktotals ( 1000 , 0. ); //Summing walk lengths
		std::vector< int > walkcounts ( 1000 , 0 ); //Counting number of walks

		if ( sum_out.is_open() and data_in.is_open() ) {

			double latitude, walklen;
			int lat_index;
			char comma;

			//First line of data_in
			std::string dummy;
			std::getline( data_in , dummy );

			int numwalks = 0;
			std::cout << std::endl;
			while( !data_in.eof() ) {

				data_in >> latitude >> comma >> walklen;

				lat_index = static_cast< int >( abs(latitude - pol_ang)*( 1000 / (MOSEY::TWO_PI/2 - pol_ang) ) );

				walktotals[ lat_index ] += walklen;
				walkcounts[ lat_index ] ++;

				if ( walklen == 0 ) {
					numwalks++;
					std::cout << "\r" << numwalks;
				}

			} //read data_in
			std::cout << "\rWriting out summary...";
			//Write out data while calculating means

			sum_out << "PolAng,MeanWalkLen" << std::endl;

			double lat, meanwalklen;
			for (unsigned int i = 0; i < 1000; i++) {

				//lat is in the middle of the bin
				lat = (i+0.5)*(MOSEY::TWO_PI/2 - pol_ang)/1000 + pol_ang;

				meanwalklen = walktotals[i]/walkcounts[i];

				sum_out << lat << "," << meanwalklen << std::endl;

			} //loop through all the bins (i)

			std::cout << "\rDONE: Summary Written  " << std::endl;

		} //files connected
		else if ( sum_out.is_open() ) {
			std::cout << "ERROR:\tUnable to open " << filename << ".csv" << std::endl;
		} //data_in problem
		else {
			std::cout << "ERROR:\tUnable to open " << filename << "_summary.csv" << std::endl;
		} //sum_out problem

		sum_out.close();
		data_in.close();

	} //Construct summary file

	return 0;
}
