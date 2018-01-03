

#ifndef MOSEY_COORDINATEWRAPPERS_HPP
#define MOSEY_COORDINATEWRAPPERS_HPP

namespace MOSEY {

	/**
	 * Defining type of functions that wrap the coordinates to keep the domain points within the domain.
	 * Call by reference, changes input coordinates to a point in the domain that would map to the same
	 * point on the manifold.
	 */
	typedef void (*CoordinateWrapperPtr)(double &u, double &v);

	/**
	 * Plane Coordinate Wrapper. Simplest coordinate wrapper because it
	 * does nothing to the coordinate point.
	 */
	CoordinateWrapperPtr PlaneWrapper(double &u, double &v);
	
	/**
	 * Sphere Coordinate Wrapper. Using most basic chart from unit square to
	 * sphere.
	 * Assumes (u,v) is not further than 1 unit outside of domain in either coordinate.
	 */
	CoordinateWrapperPtr SphereWrapper(double &u, double &v);
	
	/**
	 * Torus Coordinate Wrapper. Using most basic chart from unit square
	 * to torus.
	 * Assumes (u,v) is not further than 1 unit outside of domain in either coordinate.
	 */
	CoordinateWrapperPtr TorusWrapper(double &u, double &v);
	
}

#endif
