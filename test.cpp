
#include "MOSEY/MOSEY.hpp"

#include <iostream>

int main() {
	
	MOSEY::Plane_CurveTensor plane_ct; //Declare curvature tensor
	
	MOSEY::Stepper plane( plane_ct , 10 , &MOSEY::PlaneWrapper ); //Initialize stepper class to match curvature tensor
	
	MOSEY::OutsideCircle unitcircle( 1. , 0. , 0. ); //Define escape region
	MOSEY::Walk planewalk( 1./10 , unitcircle , &plane ); //Define clas to perform walk
	
	planewalk.Wander( 0. , 0. ); //Start from origin and walk
	
	while ( !planewalk.Empty() ) {
		
		double u,v,walklen;
		
		planewalk.StepBackward( u , v , walklen );
		
		std::cout << u << '\t' << v << '\t' << walklen << std::endl;
		
	} //StepBackward until empty
	
	return 1;
}
