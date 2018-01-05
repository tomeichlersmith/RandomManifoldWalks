

#ifndef MOSEY_CURVETENSOR_HPP
#define MOSEY_CURVETENSOR_HPP

#include <cmath>

namespace MOSEY {
	
	const long double PI = M_PI;
	const long double TWO_PI = 2*PI;
	
	/**
	 * Curvature Tensor class. A short class that stores the Christoffel symbols for a two dimensional manifold.
	 * Assumes Curvature Tensor is symmetric (i.e. uuv = uvu and vuv = vvu)
	 */
	class CurveTensor {
		public:
			/**
			 * Constructor
			 */
			CurveTensor();
			
			virtual double UUU(const double u, const double v) const;
			virtual double UUV(const double u, const double v) const;
			virtual double UVV(const double u, const double v) const;
			virtual double VUU(const double u, const double v) const;
			virtual double VUV(const double u, const double v) const;
			virtual double VVV(const double u, const double v) const;
		
		private:
			
	};
	
}

#endif
