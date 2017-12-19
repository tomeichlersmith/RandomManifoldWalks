

#include "ChristoffelSymbols.hpp"
#include "CoordinateWrappers.hpp"

namespace MOSEY {

	/**
	 * Stepper Class. Performs a Runge-Kutta approximation to the geodesic equations in order to
	 * take a single step in the Random Walk. This is performed by the public member Forward.
	 */
	class Stepper {
		public:
			/**
			 * Preferred constructor. Defines all necessary member variables explicitly
			 * @param curvetensor CurvatureTensor class instance that contains the correct Christoffel symbols
			 * @param numsteps number of steps to be used in the Runge-Kutta method
			 * @param coordwrap Coordinate Wrapping function for the manifold
			 */
			Stepper(CurvatureTensor curvetensor, int numsteps, CoordinateWrapperPtr coordwrap) :
				m_curvetensor(curvetensor), m_numsteps(numsteps), m_coordwrap(coordwrap) {}
		
			/**
			 * Default Constructructor. Defines the member variables with the default (planar) values
			 */
			Stepper() : m_curvetensor(MOSEY::ZeroTensor), m_numsteps(1), m_coordwrap(MOSEY::PlaneWrapper) {}
		
			/**
			 * function that performs the approxmation step
			 * @param u0 starting point, u coordinate
			 * @param v0 starting point, v coordinate
			 * @param direction starting angle (assumed to be from positive u-coordinate axis)
			 * @param steplen length of step that should be taken on the manifold
			 * @param u1 ending point, u coordinate
			 * @param v1 ending point, v coordinate
			 */
			Forward(double u0, double v0, double direction, double steplen, double &u1, double &v1);
		
		private:
			/**
			 * Pointers to functions defining the Christoffel symbols matching the manifold that is
			 * walked on. 
			 */
			CurvatureTensor m_curvetensor;
		
			/**
			 * Number of steps to be used in the Runge-Kutta method. (NOT to be confused with number of
			 * steps in random walk)
			 */
			int m_numsteps;
		
			/**
			 * Pointer to function that will wrap the u,v coordinates appropriately for the manifold.
			 */
			CoordinateWrapperPtr m_coordwrap;
	};

}
