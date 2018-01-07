
#include "../MOSEY/CurveTensor/Plane.hpp"

namespace MOSEY {
	
	Plane_CurveTensor::Plane_CurveTensor() : CurveTensor() {
		/* Intentionally Empty */
	}
	
	double Plane_CurveTensor::UUU(const double u, const double v) const {
		return 0;
	}
	
	double Plane_CurveTensor::UUV(const double u, const double v) const {
		return 0;
	}
	
	double Plane_CurveTensor::UVV(const double u, const double v) const {
		return 0;
	}
	
	double Plane_CurveTensor::VUU(const double u, const double v) const {
		return 0;
	}
	
	double Plane_CurveTensor::VUV(const double u, const double v) const {
		return 0;
	}
	
	double Plane_CurveTensor::VVV(const double u, const double v) const {
		return 0;
	}
	
}
