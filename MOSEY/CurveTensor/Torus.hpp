
#ifndef MOSEY_CURVETENSOR_TORUS_HPP
#define MOSEY_CURVETENSOR_TORUS_HPP

#include "../CurveTensor.hpp"

namespace MOSEY {
	
	class Torus_CurveTensor : public CurveTensor {
		public:
			
			/**
			 * Default Constructor. Assumes tube radius is 1 and hole radius is 2.
			 */
			Torus_CurveTensor();
			
			/**
			 * General Constructor. User inputs tube and hole radii.
			 */
			Torus_CurveTensor(const double tube_rad, const double hole_rad);
			
			double UUU(const double u, const double v) const;
			double UUV(const double u, const double v) const;
			double UVV(const double u, const double v) const;
			double VUU(const double u, const double v) const;
			double VUV(const double u, const double v) const;
			double VVV(const double u, const double v) const;
			
		private:
			/**
			 * Tube Radius is the radius of the circle that is revolved about an axis
			 * to form the torus.
			 */
			double m_tube_rad;
			
			/**
			 * Hole Radius is the distance from the axis of revolution to the center of the
			 * circle that is revolved.
			 */
			double m_hole_rad;
	};
	
}

#endif
