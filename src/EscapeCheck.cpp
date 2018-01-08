
#include "../MOSEY/EscapeCheck.hpp"

namespace MOSEY {
	
	bool OutsideCircle(std::vector<double> param, StepPtr step) {
		
		//Get parameters from vector
		double radius = param[0];
		double ucenter = param[1];
		double vcenter = param[2];
		
		//Get point of the step
		double u,v;
		step->StepPoint( u , v );
		
		double delu = (u - ucenter);
		double delv = (v - vcenter);
		double dist = std::sqrt( delu*delu + delv*delv );
		
		return ( dist > radius );
	}
	
}
