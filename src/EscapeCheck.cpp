
#include "../MOSEY/EscapeCheck.hpp"

namespace MOSEY {
	
	namespace EscapeCheck {
	
		bool OutsideCircle(std::vector<double> param, StepPtr step) {
		
			//Get parameters from vector
			double radius = param[0];
			double ucenter = param[1];
			double vcenter = param[2];
		
			//Get point of the step
			double u,v;
			step->StepPoint( u , v );
			
			double dist = std::sqrt( (u-ucenter)*(u-ucenter) + (v-vcenter)*(v-vcenter) );
		
			//Functional Check
			//std::cout << dist << std::endl;
		
			return ( dist > radius );
		}
		
		bool CircleRing(std::vector<double> param, StepPtr step) {
			
			//Get parameters from vector
			double in_rad = param[0];
			double out_rad = param[1];
			double ucenter = param[2];
			double vcenter = param[3];
			
			//Get point of the step
			double u,v;
			step->StepPoint( u , v );
			
			double dist = std::sqrt( (u-ucenter)*(u-ucenter) + (v-vcenter)*(v-vcenter) );
			
			return ( dist < in_rad or dist > out_rad );	
		}
	
	} //namespace EscapeCheck
	
}
