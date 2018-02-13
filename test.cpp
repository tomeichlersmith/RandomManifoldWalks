
#include "MOSEY/MOSEY.hpp"

#include <iostream>
#include <fstream>

/**
 * Function to simulate walks from (u0,v0) and output data to output
 * @param walker MOSEY::Walk that is already formated to do the walk (with a specific escape region)
 * @param u0 u coordinate of starting point
 * @param v0 v coordinate of starting point
 * @param num_walks number of walks to simulate (all output to same file)
 * @param output output stream (usually file stream) that will receive the data
 */
void SimulateWalks( MOSEY::Walk walker , double u0, double v0, int num_walks , std::ostream& output );

int main() {
	/*
	MOSEY::Walk spherewalk( MOSEY::Manifold::Sphere ); //Define class instance to perform walk
	spherewalk.SetStepLength( 0.05 );
	std::vector<double> params( 1 , 0.5 );
	spherewalk.SetEscapeRegion( &MOSEY::EscapeCheck::VThresh , params );
	spherewalk.SetMaxWalkLength( 1000. );
	*/
	MOSEY::Walk planewalk( MOSEY::Manifold::Plane );
	planewalk.SetStepLength( 0.05 );
	std::vector<double> circle_params( 4 , 0. );
	circle_params[0] = 1.;
	circle_params[1] = 3.;
	planewalk.SetEscapeRegion( &MOSEY::EscapeCheck::CircleRing , circle_params );
	planewalk.SetMaxWalkLength( 1000. );
	
	std::ofstream plane_unitcircle_out;
	plane_unitcircle_out.open("../Data/Plane_CircleRing_1_3.csv");//, std::ofstream::app );
	plane_unitcircle_out << "R,WalkLen" << std::endl;
	
	if ( plane_unitcircle_out.is_open() ) {
		
		for (int i = 0; i < 200; i++) {
		
			planewalk.Wander( 0. , 2. );
		
			planewalk.Export( plane_unitcircle_out , MOSEY::ExportType::Radius );
		
		} //simulating num_walks walks
	}
	else {
		std::cout << "ERROR:\tUnable to open ../Data/Plane_UnitCircle.csv" << std::endl;
	}
	
	plane_unitcircle_out.close();
	
	return 0;
}

void SimulateWalks( MOSEY::Walk walker , double u0 , double v0 , int num_walks , std::ostream& output ) {
	
	
	
	return;
}
