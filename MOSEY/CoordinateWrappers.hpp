
/**
 * Defining type of functions that wrap the coordinates to keep the domain points within the domain.
 * Call by reference, changes input coordinates to a point in the domain that would map to the same
 * point on the manifold.
 */
typedef void (*CoordinateWrapperPtr)(double &u, double &v);
