
#include "MOSEY/MOSEY.hpp"

#include <iostream>
#include <fstream>

#include <cmath> //cot

int main() {
	///*
	MOSEY::Walk spherewalk( MOSEY::Manifold::Sphere );
	spherewalk.SetStepLength( 0.05 );
	std::vector<double> params( 2 , 0. );
	double pol_ang = MOSEY::TWO_PI/8;
	params[0] = sin(pol_ang)/(1-cos(pol_ang)); //Change radius of circle in (u,v)-space
	spherewalk.SetEscapeRegion( &MOSEY::EscapeCheck::OutsideCircle , params );
	spherewalk.SetMaxWalkLength( 1000. );
	//*/
	/*
	MOSEY::Walk planewalk( MOSEY::Manifold::Plane );
	planewalk.SetStepLength( 0.05 );
	std::vector<double> circle_params( 4 , 0. );
	circle_params[0] = 1.;
	circle_params[1] = 3.;
	planewalk.SetEscapeRegion( &MOSEY::EscapeCheck::CircleRing , circle_params );
	planewalk.SetMaxWalkLength( 1000. );
	//*/
	std::ofstream outs;
	outs.open("../Data/Sphere_CircleRing_2PI_8.csv");//, std::ofstream::app );
	outs << "Ang,WalkLen" << std::endl;
	
	if ( outs.is_open() ) {
		
		for (int i = 0; i < 2; i++) {
		
			spherewalk.Wander( 0. , 0. );
		
			spherewalk.Export( outs , MOSEY::ExportType::PolarAng );
		
		} //simulating num_walks walks
	}
	else {
		std::cout << "ERROR:\tUnable to open ../Data/Plane_UnitCircle.csv" << std::endl;
	}
	
	outs.close();
	
	return 0;
}

