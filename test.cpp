
#include "MOSEY/MOSEY.hpp"

#include <iostream>

int main() {
	
	MOSEY::Walk spherewalk( MOSEY::Manifold::Sphere ); //Define class instance to perform walk
	spherewalk.SetStepLength( 0.05 );
	std::vector<double> params( 1 , 0.5 );
	spherewalk.SetEscapeRegion( &MOSEY::EscapeCheck::VThresh , params );
	
	spherewalk.SetMaxWalkLength( 1000. );
	
	for (int i = 0; i < 1; i++ ) {
		
		spherewalk.Wander( 0. , 0.001 ); //Start from origin and walk
	
		double walklen;
		double ucurr,vcurr;
		
		while ( !spherewalk.Empty() ) {
		
			spherewalk.StepBackward( ucurr , vcurr , walklen );
		
			std::cout << ucurr << '\t' << vcurr << '\t' << walklen << std::endl;
		
		} //StepBackward until empty
		
		//std::cout << walklen << std::endl;
	}
	
	
	return 0;
}
