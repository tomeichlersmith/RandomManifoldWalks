
#include "MOSEY/MOSEY.hpp"

#include <iostream>

int main() {
	
	MOSEY::Walk planewalk( MOSEY::Manifold::PlaneSquare ); //Define class instance to perform walk
	planewalk.SetStepLength( 0.1 );
	std::vector<double> circle_params( 4 , 0. ); //list of 4 zeros
	circle_params[0] = 0.25; //Change innter radius
	circle_params[1] = 3; //Change outer radius
	planewalk.SetEscapeRegion( &MOSEY::EscapeCheck::CircleRing , circle_params );
	
	planewalk.SetMaxWalkLength( 1000. );
	
	for (int i = 0; i < 1; i++ ) {
		
		planewalk.Wander( 0.75 , 0. ); //Start from origin and walk
	
		double walklen;
		double ucurr,vcurr;
		
		while ( !planewalk.Empty() ) {
		
			planewalk.StepBackward( ucurr , vcurr , walklen );
		
			std::cout << ucurr << '\t' << vcurr << '\t' << walklen << std::endl;
		
		} //StepBackward until empty
		
		//std::cout << walklen << std::endl;
	}
	
	
	return 0;
}
