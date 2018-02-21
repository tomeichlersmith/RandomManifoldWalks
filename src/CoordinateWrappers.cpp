
#include "../MOSEY/CoordinateWrappers.hpp"

namespace MOSEY {
	
	namespace CoordinateWrapper {
	
		void Plane(double uprev, double vprev, double& ucurr, double& vcurr) { 
		
			/* Intentionally Empty */
	
			return;
		}
		
		void PlaneUnitDisk(double uprev, double vprev, double& ucurr, double& vcurr) {
			
			double dist = std::sqrt( ucurr*ucurr + vcurr*vcurr );
			
			if ( dist > 1 ) {
			
				//intersection point with unit circle
				//normal to intersection point
				//reflect over circle
				
			} //if (ucurr,vcurr) is outside unit disk
		}
		
		void PlaneSquare(double uprev, double vprev, double& ucurr, double& vcurr) {
			
			if ( std::abs(u) > 1 or std::abs(v) > 1 ) {
				
				//bounce off of walls
				if ( u > 1 )
					ucurr = 2-ucurr; //1-(u-1) = 1-u+1 = 2-u
				else if ( ucurr < -1 )
					ucurr = -2-ucurr; //-1-(u+1) = -1-u-1 = -2-u
				
				if ( v > 1 )
					vcurr = 2-vcurr;
				else if ( v < -1 )
					vcurr = -2-vcurr;
				
			} //(ucurr,vcurr) outside square
			
			return;
		}

		void Sphere(double uprev, double vprev, double& ucurr, double& vcurr) {
			
			/* Intentionally Empty */
			
			return;
		}

		void Torus(double uprev, double vprev, double& ucurr, double& vcurr) {
		
			//If exit in u-coordinate, transport to other side of domain
			if ( ucurr < 0 ) {
				ucurr = 1+ucurr;
			}
			else if ( ucurr >= 1 ) {
				ucurr = ucurr-1;
			}
		
			//If exit in v-coordinate, transport to other side of domain
			if ( vcurr < 0 ) {
				vcurr = 1+vcurr;
			}
			else if ( vcurr >= 1 ) {
				vcurr = vcurr-1;
			}
		
			return;
		}
	
	} //namespace CoordinateWrapper
	
}
