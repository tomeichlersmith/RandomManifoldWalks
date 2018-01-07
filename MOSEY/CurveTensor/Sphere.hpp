
#ifndef MOSEY_CURVETENSOR_SPHERE_HPP
#define MOSEY_CURVETENSOR_SPHERE_HPP

#include "../CurveTensor.hpp"

namespace MOSEY {
	
	class Sphere_CurveTensor : public CurveTensor {
		public:
			
			/**
			 * Default Constructor. Assumes unit radius sphere.
			 */
			Sphere_CurveTensor();
			
			/**
			 * General Constructor. User inputs radius of sphere.
			 * It should be noted that the sphere's christoffel symbols do not depend on the radius.
			 */
			Sphere_CurveTensor(const double radius);
			
			double UUU(const double u, const double v) const;
			double UUV(const double u, const double v) const;
			double UVV(const double u, const double v) const;
			double VUU(const double u, const double v) const;
			double VUV(const double u, const double v) const;
			double VVV(const double u, const double v) const;
			
		private:
			double m_radius;
	};
	
}

#endif
