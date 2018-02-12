
#include "../MOSEY/CoordinateWrappers.hpp"

namespace MOSEY {
	
	namespace CoordinateWrapper {
	
		void Plane(double& u, double& v) { 
		
			/* Intentionally Empty */
	
			return;
		}
		
		/*void PlaneUnitDisk(double& u, double& v) {
			
			double dist = u*u + v*v;
			
		}*/
		
		void PlaneSquare(double& u, double& v) {
			
			if ( std::abs(u) > 1 or std::abs(v) > 1 ) {
				
				if ( u > 1 )
					u = 2-u; //1-(u-1) = 1-u+1 = 2-u
				else if ( u < -1 )
					u = -2-u; //-1-(u+1) = -1-u-1 = -2-u
				
				if ( v > 1 )
					v = 2-v; //1-(u-1) = 1-u+1 = 2-u
				else if ( v < -1 )
					v = -2-v; //-1-(u+1) = -1-u-1 = -2-u
				
			} //(u,v) outside square
			
			return;
		}

		void Sphere(double &u, double &v) {
		
			//If exit in v-coordinate, bounce back and add 1/2 to u-coordinate
			if ( v < 0 ) {
				v = -1*v;
				u += 0.5;
			}
			else if ( v >= 1 ) {
				v = 2-v; // v = 1-(v-1) = 1-v+1 = 2-v
				u += 0.5;
			}
		
			//If exit in u-coordinate, transport to other side of domain
			//Done after v-coordinate because v-coordinate may change u-coordinate
			if ( u < 0 ) {
				u = 1+u;
			}
			else if ( u >= 1 ) {
				u = u-1;
			}
		
			return;
		}

		void Torus(double &u, double &v) {
		
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
	
	} //namespace CoordinateWrapper
	
}
