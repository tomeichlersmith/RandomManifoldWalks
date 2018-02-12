
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
	circle_params[0] = 0.;
	circle_params[1] = 1.;
	planewalk.SetEscapeRegion( &MOSEY::EscapeCheck::CircleRing , circle_params );
	planewalk.SetMaxWalkLength( 1000. );
	
	std::ofstream plane_unitcircle_out;
	plane_unitcircle_out.open("../Data/Plane_UnitCircle.csv", std::ofstream::app );
	//plane_unitcircle_out << "U,V,WalkLen" << std::endl;
	
	if ( plane_unitcircle_out.is_open() ) {
		SimulateWalks( planewalk , 0. , 0. , 100 , plane_unitcircle_out );
	}
	else {
		std::cout << "ERROR:\tUnable to open ../Data/Plane_UnitCircle.csv" << std::endl;
	}
	
	plane_unitcircle_out.close();
	
	return 0;
}

void SimulateWalks( MOSEY::Walk walker , double u0 , double v0 , int num_walks , std::ostream& output ) {
	
	for (int i = 0; i < num_walks; i++) {
		
		walker.Wander( u0 , v0 );
		
		walker.Export( output );
		
	} //simulating num_walks walks
	
	return;
}
