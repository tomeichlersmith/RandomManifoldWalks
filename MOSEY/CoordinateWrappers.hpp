

#ifndef MOSEY_COORDINATEWRAPPERS_HPP
#define MOSEY_COORDINATEWRAPPERS_HPP

#include <cmath> //abs

namespace MOSEY {

	/**
	 * Defining type of functions that wrap the coordinates to keep the domain points within the domain.
	 * Call by reference, changes input coordinates to a point in the domain that would map to the same
	 * point on the manifold.
	 */
	typedef void (*CoordinateWrapperPtr)(double &u, double &v);
	
	namespace CoordinateWrapper {
	
		/**
		 * Plane Coordinate Wrapper. Simplest coordinate wrapper because it
		 * does nothing to the coordinate point.
		 */
		void Plane(double& u, double& v);
		
		/**
		 * Plane Coordinate Wrapper, but points are restricted to being
		 * within the unit disk. If a step goes outside the unit disk,
		 * it is reflected over the unit circle.
		 */
		//void PlaneUnitDisk(double& u, double& v);
		
		/**
		 * Plane Coordinate Wrapper, but points are restricted to being
		 * within a square with corners on (1,1);(1,-1);(-1,1);(-1,-1)
		 * If a step goes outside this square, it is reflected over the
		 * side(s) it crossed
		 */
		void PlaneSquare(double& u, double& v);
	
		/**
		 * Sphere Coordinate Wrapper. Stereographic projection of Sphere onto plane.
		 * This chart does not have a bound on the domain points (so does nothing).
		 */
		void Sphere(double& u, double& v);
		
		/**
		 * Torus Coordinate Wrapper. Using most basic chart from unit square
		 * to torus.
		 * Assumes (u,v) is not further than 1 unit outside of domain in either coordinate.
		 */
		void Torus(double& u, double& v);
	
	} //namespace CoordinateWrapper
	
}

#endif
