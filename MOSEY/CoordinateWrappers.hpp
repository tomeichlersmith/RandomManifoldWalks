

#ifndef MOSEY_COORDINATEWRAPPERS_HPP
#define MOSEY_COORDINATEWRAPPERS_HPP

#include <cmath> //abs
#include <iostream> //Funcitonal Checks

namespace MOSEY {

	/**
	 * Defining type of functions that wrap the coordinates to keep the domain points within the domain.
	 * Call by reference, changes input coordinates to a point in the domain that would map to the same
	 * point on the manifold.
	 * Previous point (uprev,vprev) is input as well as current point (ucurr,vcurr) so that "bouncing"
	 * off the walls can be implemented.
	 * @param uprev previous u coordinate (call by value)
	 * @param vprev previous v coordinate (call by value)
	 * @param ucurr current u coordinate (call by reference)
	 * @param vcurr current v coordinate (call by reference)
	 */
	typedef void (*CoordinateWrapperPtr)(double uprev, double vprev, double &ucurr, double &vcurr);

	namespace CoordinateWrapper {

		/**
		 * Plane Coordinate Wrapper. Simplest coordinate wrapper because it
		 * does nothing to the coordinate point.
		 */
		void Plane(double uprev, double vprev, double& ucurr, double& vcurr);

		/**
		 * Plane Coordinate Wrapper, but points are restricted to being
		 * within the unit disk. If a step goes outside the unit disk,
		 * it is reflected over the unit circle.
		 * Assumes (uprev,vprev) is within the unit disk.
		 */
		void PlaneUnitDisk(double uprev, double vprev, double& ucurr, double& vcurr);

		/**
		 * Plane Coordinate Wrapper, but points are restricted to being
		 * within a square with corners on (1,1);(1,-1);(-1,1);(-1,-1)
		 * If a step goes outside this square, it is reflected over the
		 * side(s) it crossed
		 */
		void PlaneSquare(double uprev, double vprev, double& ucurr, double& vcurr);

		/**
		 * Sphere Coordinate Wrapper. Stereographic projection of Sphere onto plane.
		 * This chart does not have a bound on the domain points (so does nothing).
		 */
		void Sphere(double uprev, double vprev, double& ucurr, double& vcurr);

		/**
		 * Torus Coordinate Wrapper. Using most basic chart from unit square
		 * to torus.
		 * Assumes (u,v) is not further than 1 unit outside of domain in either coordinate.
		 */
		void Torus(double uprev, double vprev, double& ucurr, double& vcurr);

	} //namespace CoordinateWrapper

}

#endif
