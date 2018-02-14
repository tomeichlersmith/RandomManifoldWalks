
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
 * argv[5] name of data storage file (output.csv) - put into data/ directory
 */
int main( int argc , char* argv[] ) {
	
	//Default Value
	double pol_ang = MOSEY::TWO_PI/8;
	int num_walks = 1;
	double steplen = 0.05;
	double max_walk_len = 1000.;
	std::string filename = "output.csv";
	
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
	outs.open( ("data/"+filename).c_str() );
	
	if( outs.is_open() ) {
		
		outs << "PolAng,WalkLen" << std::endl;
		
		for( int i = 0; i < num_walks; i++ ) {
			
			spherewalk.Wander( 0. , 0. );
			
			spherewalk.Export( outs , MOSEY::ExportType::PolarAng );
			
		}
		
	}
	else {
	
		std::cout << "ERROR:\tUnable to open " << filename << std::endl;
		
	}
	
	outs.close();
	
	return 0;
}
