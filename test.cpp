
#include "MOSEY/MOSEY.hpp"

#include <iostream>

int main() {
	
	MOSEY::Walk planewalk( MOSEY::Manifold::Plane ); //Define class instance to perform walk
	planewalk.SetStepLength( 0.01 );
	std::vector<double> circle_params( 4 , 0. ); //list of 4 zeros
	circle_params[0] = 1; //Change innter radius
	circle_params[1] = 3; //Change outer radius
	planewalk.SetEscapeRegion( &MOSEY::EscapeCheck::CircleRing , circle_params );
	
	planewalk.SetMaxWalkLength( 1000. );
	
	for (int i = 0; i < 10; i++ ) {
		
		planewalk.Wander( 2. , 0. ); //Start from origin and walk
	
		double walklen;
		double ucurr,vcurr;
		
		while ( !planewalk.Empty() ) {
		
			planewalk.StepBackward( ucurr , vcurr , walklen );
		
			//std::cout << ucurr << '\t' << vcurr << '\t' << walklen << std::endl;
		
		} //StepBackward until empty
		
		std::cout << walklen << std::endl;
	}
	
	
	return 0;
}
