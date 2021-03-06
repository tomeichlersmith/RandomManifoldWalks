
#include "MOSEY/MOSEY.hpp"

#include <string> //Processing inputs

int main(  ) {
	
	
	MOSEY::Walk spherewalk( MOSEYManifold::Sphere );
	spherewalk.SetStepLength( steplen );
	std::vector<double> params( 3 , 0. );
	params[0] = sin(pol_ang)/(1-cos(pol_ang)); //Change radius of circle to (u,v)-space
	spherewalk.SetEscapeRegion( &EscapeCheck::OutsideCircle , params );
	spherewalk.SetMaxWalkLength( 1000. );
	
	std::ofstream outs;
	outs.open( filepath );
	
	if( outs.is_open() ) {
		
		outs << "PolAng,WalkLen" << std::endl;
		
		for( int i = 0; i < numwalks; i++ ) {
			
			spherewalk.Wander( 0. , 0. );
			
			spherewalk.Export( outs , ExportType::PolarAng );
			
		}
		
	}
	else {
	
		std::cout << "ERROR:\tUnable to open " << filepath << std::endl;
		
	}
	
	outs.close();
	
	return 0;
}

