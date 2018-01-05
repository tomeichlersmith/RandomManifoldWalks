
#include "../MOSEY/Sphere_CurveTensor.hpp"

namespace MOSEY {
	
	Sphere_CurveTensor::Sphere_CurveTensor() : CurveTensor() , m_radius(1.) {
		/* Intentionally Empty */
	}
	
	Sphere_CurveTensor::Sphere_CurveTensor(const double radius) : CurveTensor() , m_radius(radius) {
		/* Intentionally Empty */
	}
	
	double Sphere_CurveTensor::UUU(const double u, const double v) const {
		return 0;
	}
	
	double Sphere_CurveTensor::UUV(const double u, const double v) const {
		
		double sinv = sin( PI*v );
		double cosv = cos( PI*v );
		
		return ( PI*( cosv / sinv ) );
	}
	
	double Sphere_CurveTensor::UVV(const double u, const double v) const {
		return 0;
	}
	
	double Sphere_CurveTensor::VUU(const double u, const double v) const {
		return ( -1*TWO_PI*sin( TWO_PI*v ) );
	}
	
	double Sphere_CurveTensor::VUV(const double u, const double v) const {
		return 0;
	}
	
	double Sphere_CurveTensor::VVV(const double u, const double v) const {
		return 0;
	}
	
}
