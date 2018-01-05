
#include "../MOSEY/Torus_CurveTensor.hpp"

namespace MOSEY {
	
	Torus_CurveTensor::Torus_CurveTensor() : CurveTensor() , m_tube_rad(1.) , m_hole_rad(2.) {
		/* Intentionally Empty */
	}
	
	Torus_CurveTensor::Torus_CurveTensor(const double tube_rad, const double hole_rad) : 
		CurveTensor() , m_tube_rad(tube_rad) , m_hole_rad(hole_rad) {
		/* Intentionally Empty */
	}
	
	double Torus_CurveTensor::UUU(const double u, const double v) const {
		return 0;
	}
	
	double Torus_CurveTensor::UUV(const double u, const double v) const {
		
		double num = -1*TWO_PI*m_tube_rad*sin( TWO_PI*v );
		double den = m_hole_rad + m_tube_rad*cos( TWO_PI*v );
		
		return ( num / den );
	}
	
	double Torus_CurveTensor::UVV(const double u, const double v) const {
		return 0;
	}
	
	double Torus_CurveTensor::VUU(const double u, const double v) const {
		return ( ( TWO_PI / m_tube_rad )*( m_hole_rad + m_tube_rad*cos( TWO_PI*v ) )*sin( TWO_PI*v ) );
	}
	
	double Torus_CurveTensor::VUV(const double u, const double v) const {
		return 0;
	}
	
	double Torus_CurveTensor::VVV(const double u, const double v) const {
		return 0;
	}
	
}
