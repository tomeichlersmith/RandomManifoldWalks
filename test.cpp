
#include "MOSEY/MOSEY.hpp"

#include <iostream>

int main() {
	
	MOSEY::Walk planewalk( MOSEY::Manifold::Plane ); //Define class instance to perform walk
	planewalk.SetStepLength( 1 );
	std::vector<double> circle_params( 3 , 0. ); //list of 3 zeros
	circle_params[0] = 50; //Change radius
	planewalk.SetEscapeRegion( &MOSEY::EscapeCheck::OutsideCircle , circle_params );
	
	planewalk.SetMaxWalkLength( 100000. );
	
	for (int i = 0; i < 10; i++ ) {
		
		planewalk.Wander( 0. , 0. ); //Start from origin and walk
	
		double walklen;
		
		while ( !planewalk.Empty() ) {
		
			double u,v;
		
			planewalk.StepBackward( u , v , walklen );
		
			//std::cout << u << '\t' << v << '\t' << walklen << std::endl;
		
		} //StepBackward until empty
		
		std::cout << walklen << std::endl;
	}
	
	return 0;
}
