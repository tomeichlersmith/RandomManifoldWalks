
#include "../MOSEY/CurveTensor.hpp"

namespace MOSEY {
	
	namespace ChristoffelSymbol {
	
		double Zero(double u, double v) {
			return 0;
		}
	
		double SphereUUV(double u, double v) {
		
			double sinv = sin( PI*v );
			double cosv = cos( PI*v );
		
			return ( PI*( cosv / sinv ) );
		}
	
		double SphereVUU(double u, double v) {
			return ( -1*TWO_PI*sin( TWO_PI*v ) );
		}
	
		double TorusUUV(double u, double v) {
		
			double m_tube_rad = 1., m_hole_rad = 2.;
			double num = -1*TWO_PI*m_tube_rad*sin( TWO_PI*v );
			double den = m_hole_rad + m_tube_rad*cos( TWO_PI*v );
		
			return ( num / den );
		}
	
		double TorusVUU(double u, double v) {
		
			double m_tube_rad = 1., m_hole_rad = 2.;
		
			return ( ( TWO_PI / m_tube_rad )*( m_hole_rad + m_tube_rad*cos( TWO_PI*v ) )*sin( TWO_PI*v ) );
		}
	
	} //namespace Christoffel Symbol
	
	CurveTensor::CurveTensor() : m_uuu(&ChristoffelSymbol::Zero), m_uuv(&ChristoffelSymbol::Zero), m_uvv(&ChristoffelSymbol::Zero), 
		m_vuu(&ChristoffelSymbol::Zero), m_vuv(&ChristoffelSymbol::Zero), m_vvv(&ChristoffelSymbol::Zero) {
		/* Intentionally Empty */
	}
	
	CurveTensor::CurveTensor( Manifold m ) : CurveTensor() {
		
		//Default constructor sets all symbols to zero symbol, so only change non-zero ones
		switch ( m ) {
			case Manifold::Sphere: m_uuv = &ChristoffelSymbol::SphereUUV; m_vuu = &ChristoffelSymbol::SphereVUU;
								break;
			case Manifold::Torus : m_uuv = &ChristoffelSymbol::TorusUUV; m_vuu = &ChristoffelSymbol::TorusVUU;
								break;
			case Manifold::Plane : break; //Do nothing
			case Manifold::PlaneSquare : break; //Do nothing
			default : break; //Do Nothing
		}
		
	}
	
	CurveTensor::CurveTensor( ChristoffelSymbolPtr uuu, ChristoffelSymbolPtr uuv, ChristoffelSymbolPtr uvv,
									 					ChristoffelSymbolPtr vuu, ChristoffelSymbolPtr vuv, ChristoffelSymbolPtr vvv ) :
		m_uuu(uuu), m_uuv(uuv), m_uvv(uvv), m_vuu(vuu), m_vuv(vuv), m_vvv(vvv) {
		/* Intentionally Empty */
	}
	
	double CurveTensor::UUU(double u, double v) const {
		return m_uuu(u,v);
	}
	
	double CurveTensor::UUV(double u, double v) const {
		return m_uuv(u,v);
	}
	
	double CurveTensor::UVV(double u, double v) const {
		return m_uvv(u,v);
	}
	
	double CurveTensor::VUU(double u, double v) const {
		return m_vuu(u,v);
	}
	
	double CurveTensor::VUV(double u, double v) const {
		return m_vuv(u,v);
	}
	
	double CurveTensor::VVV(double u, double v) const {
		return m_vvv(u,v);
	}
	
}
