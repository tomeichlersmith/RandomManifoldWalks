
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
				//Solve quadratic equation to find point of intersection between ray
				// (uprev,vprev) -> (ucurr,vcurr) intersects unit circle
				double a = (ucurr-uprev)*(ucurr-uprev)+(vcurr-vprev)*(vcurr-vprev);
				double b = 2*((ucurr-uprev)*(uprev)+(vcurr-vprev)*(vprev));
				double c = uprev*uprev+vprev*vprev - 1.;
				double disc = std::sqrt( b*b - 4*a*c );

				//Find intersection point by deterimining t that is in between (uprev,vprev)
				// and (ucurr,vcurr)
				double t1 = (-b + disc)/(2*a);
				double t2 = (-b - disc)/(2*a);
				double t;
				if (0 <= t1 and t1 <= 1)
					t = t1;
				else if ( 0 <= t2 and t2 <= 1)
					t = t2;
				else {
					std::cout << "ERROR:\tNo Intersection with Border!" << std::endl;
					exit(1);
				}

				//Intersection point
				double uinter = (1-t)*uprev + t*ucurr;
				double vinter = (1-t)*vprev + t*vcurr;

				//determine unit tangent vector to intersection point
				double slope_x = vinter;
				double slope_y = -uinter;
				double slope_mag = std::sqrt(slope_x*slope_x + slope_y*slope_y);
				slope_x = slope_x/slope_mag;
				slope_y = slope_y/slope_mag;

				//Project vector (uinter,vinter)->(ucurr,vcurr) onto slope vector
				double proj = ((ucurr-uinter)*(slope_x) + (vcurr-vinter)*slope_y);
				double proj_x = proj*slope_x;
				double proj_y = proj*slope_y;

				//Find perpendicular component (and reflect it over slope vector)
				double perp_x = -1*((ucurr-uinter)-proj_x);
				double perp_y = -1*((vcurr-vinter)-proj_y);

				//Add reflected perpindicular component to projection vector
				ucurr = uinter + proj_x + perp_x;
				vcurr = vinter + proj_y + perp_y;

			} //if (ucurr,vcurr) is outside unit disk

			//Functional Check
			//std::cout << ucurr << "," << vcurr << "\t" << std::sqrt(ucurr*ucurr+vcurr*vcurr) << std::endl;
			
			return;
		}

		void PlaneSquare(double uprev, double vprev, double& ucurr, double& vcurr) {

			if ( std::abs(ucurr) > 1 or std::abs(vcurr) > 1 ) {

				//bounce off of walls
				if ( ucurr > 1 )
					ucurr = 2-ucurr; //Reflect over positive wall: 1-(u-1) = 1-u+1 = 2-u
				else if ( ucurr < -1 )
					ucurr = -2-ucurr; //Reflect over negative wall: -1-(u+1) = -1-u-1 = -2-u

				if ( vcurr > 1 )
					vcurr = 2-vcurr;
				else if ( vcurr < -1 )
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
