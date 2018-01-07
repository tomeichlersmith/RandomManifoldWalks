
#ifndef MOSEY_CURVETENSOR_PLANE_HPP
#define MOSEY_CURVETENSOR_PLANE_HPP

#include "../CurveTensor.hpp"

namespace MOSEY {
	
	class Plane_CurveTensor : public CurveTensor {
		public:
			
			/**
			 * Default Constructor. No variables to specify type of plane.
			 * All elements of curvature tensor are zero.
			 */
			Plane_CurveTensor();
			
			double UUU(const double u, const double v) const;
			double UUV(const double u, const double v) const;
			double UVV(const double u, const double v) const;
			double VUU(const double u, const double v) const;
			double VUV(const double u, const double v) const;
			double VVV(const double u, const double v) const;
			
		private:
			
	};
	
}

#endif
