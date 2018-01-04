
#include "../MOSEY/CoordinateWrappers.hpp"

namespace MOSEY {
	
	CoordinateWrapperPtr PlaneWrapper(double &u, double &v) { 
		
		/* Intentionally Empty */
		
		return;
	}
	
	CoordinateWrapperPtr SphereWrapper(double &u, double &v) {
		
		//If exit in u-coordinate, bounce back and add 1/2 to v-coordinate
		if ( u < 0 ) {
			u = -1*u;
			v += 0.5;
		}
		else if ( u >= 1 ) {
			u = 2-u; // u = 1-(u-1) = 1-u+1 = 2-u
			v += 0.5;
		}
		
		//If exit in v-coordinate, transport to other side of domain
		//Done after u-coordinate because u-coordinate may change v-coordinate
		if ( v < 0 ) {
			v = 1+v;
		}
		else if ( v >= 1 ) {
			v = v-1;
		}
		
		return;
	}
	
	CoordinateWrapperPtr TorusWrapper(double &u, double &v) {
		
		//If exit in u-coordinate, transport to other side of domain
		if ( u < 0 ) {
			u = 1+u;
		}
		else if ( u >= 1 ) {
			u = u-1;
		}
		
		//If exit in v-coordinate, transport to other side of domain
		if ( v < 0 ) {
			v = 1+v;
		}
		else if ( v >= 1 ) {
			v = v-1;
		}
		
		return;
	}
	
	
}
