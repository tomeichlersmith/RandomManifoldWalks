
#include "../MOSEY/MOSEY.hpp"

#include <string> //Processing inputs
#include <sstream> //Making filepath
#include <iostream>
#include <fstream>
#include <cmath> //for cos and sin

#define NBINS 500

/**
 * Description of argv[] array for inputs (default value)
 * argv[0] name of program (./run/TorusWalk)
 * argv[1] minimum u coordinate to be in escape region (0)
 * argv[2] maximum u coordinate to be in escape region (0.5)
 * argv[3] minimum v coordinate to be in escape region (0)
 * argv[4] maximum v coordinate to be in escape region (0.5)
 * argv[5] number of walks (100)
 * argv[6] length of each step of the walk (0.05)
 * argv[7] maximum walk length (2000)
 * argv[8] name of data storage file (output) - put into data/ directory
 */
int main( int argc , char* argv[] ) {

	//Default Value
	double umin = 0, umax = 0.25;
	double vmin = 0, vmax = 0.25;
	int num_walks = 100;
	double steplen = 0.05;
	double max_walk_len = 2000.;
	std::string filename = "output";

	switch( argc ) {
		case 9 : //Go through all settings, breaking before defaults
			filename = static_cast<std::string>(argv[8]);
		case 8 :
			max_walk_len = std::stod( static_cast<std::string>(argv[7]) );
		case 7 :
			steplen = std::stod( static_cast<std::string>(argv[6]) );
		case 6 :
			num_walks = std::stoi( static_cast<std::string>(argv[5]) );
		case 5 :
			vmax = std::stod( static_cast<std::string>(argv[4]) );
		case 4 :
			vmin = std::stod( static_cast<std::string>(argv[3]) );
		case 3 :
			umax = std::stod( static_cast<std::string>(argv[2]) );
		case 2 :
			umin = std::stod( static_cast<std::string>(argv[1]) );
		default : //Keep defaults set above
			break;
	}

	MOSEY::Walk walk( MOSEY::Manifold::Torus );
	walk.SetStepLength( steplen );
	std::vector<double> params( 4 , 0. );
	params[0] = umin; //umin for box
	params[1] = umax; //umax for box
	params[2] = vmin; //vmin for box
	params[3] = vmax; //vmax for box
	walk.SetEscapeRegion( &MOSEY::EscapeCheck::InsideBox , params );
	walk.SetMaxWalkLength( max_walk_len );

	std::ofstream outs;
	outs.open( ("Torus/data/"+filename+".csv").c_str() );

	if( outs.is_open() ) {

		outs << "U,V,WalkLen" << std::endl;
		
		//Calculate starting (u,v)
		//	works if [u,v]max > [u,v]min
		double ustart,vstart;
		ustart = umax + (umax - umin)/2;
		vstart = vmax + (vmax - vmin)/2;
		MOSEY::CoordinateWrapper::Torus( 0 , 0 , ustart , vstart ); //wraps back into domain

		for( int i = 0; i < num_walks; i++ ) {

			walk.Wander( ustart , vstart );
			
			walk.Export( outs , MOSEY::ExportType::UV );

			std::cout << "[" << i << "/" << num_walks << "] completed...\r" << std::flush;

		}

	}
	else {
		std::cout << "ERROR:\tUnable to open " << filename << std::endl;
		exit(1);
	}

	outs.close();

	std::cout << "Number of Simulated Walks that Ended Before Escaping: " << walk.MaxWalkCount() << std::endl;
	if ( walk.MaxWalkCount() > 1 )
		std::cout << "\tYou may wish to re-run with a higher maximum walk length." << std::endl;

	char answer;
	std::cout << "Construct summary file from generated data? (y/n) ";
	std::cin >> answer;

	if ( answer == 'y' or answer == 'Y' ) {

		//Output File Declaration
		std::ofstream sum_out;
		sum_out.open( ("Torus/data/"+filename+"_summary.csv").c_str() );

		//Input File Declaration
		std::ifstream data_in;
		data_in.open( ("Torus/data/"+filename+".csv").c_str() );

		//Data Storage Vectors
		// Store data in bins
		double walktotals[NBINS][NBINS]; //Summing walk lengths
		int walkcounts[NBINS][NBINS]; //Counting number of walks
		for (int ui = 0; ui < NBINS; ui++) {
			for (int vi = 0; vi < NBINS; vi++) {
				walktotals[ui][vi] = 0.;
				walkcounts[ui][vi] = 0;
			} //vi
		} //ui

		if ( sum_out.is_open() and data_in.is_open() ) {

			double u, v, walklen;
			int ui, vi;
			char comma;

			//First line of data_in
			std::string dummy;
			std::getline( data_in , dummy );

			int numwalks = 0;
			std::cout << std::endl;
			while( !data_in.eof() ) {

				data_in >> u >> comma >> v >> comma >> walklen;

				ui = static_cast< int >( u*NBINS );
				vi = static_cast< int >( v*NBINS );

				walktotals[ ui ][ vi ] += walklen;
				walkcounts[ ui ][ vi ] ++;

				if ( walklen == 0 ) {
					numwalks++;
					std::cout << "\r" << numwalks << std::flush;
				}

			} //read data_in
			std::cout << "\rWriting out summary...";
			//Write out data while calculating means

			sum_out << "U,V,MeanWalkLen" << std::endl;

			double meanwalklen;
			for (int ui = 0; ui < NBINS; ui++) {
				for (int vi = 0; vi < NBINS; vi++) {

					if ( walkcounts[ui][vi] > 0 ) {
						u = (ui+0.5)/NBINS;
						v = (vi+0.5)/NBINS;
						meanwalklen = walktotals[ui][vi]/walkcounts[ui][vi];

						sum_out << u << ',' << v << ',' << meanwalklen << std::endl;
					} //if bin has some data in it

				} //loop through vi
			} //loop through ui

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
