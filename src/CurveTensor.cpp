
#include "../MOSEY/CurveTensor.hpp"

namespace MOSEY {
	
	double ZeroSymbol(double u, double v) {
		return 0;
	}
	
	double SphereUUVSymbol(double u, double v) {
		
		double sinv = sin( PI*v );
		double cosv = cos( PI*v );
		
		return ( PI*( cosv / sinv ) );
	}
	
	double SphereVUUSymbol(double u, double v) {
		return ( -1*TWO_PI*sin( TWO_PI*v ) );
	}
	
	double TorusUUVSymbol(double u, double v) {
		
		double m_tube_rad = 1., m_hole_rad = 2.;
		double num = -1*TWO_PI*m_tube_rad*sin( TWO_PI*v );
		double den = m_hole_rad + m_tube_rad*cos( TWO_PI*v );
		
		return ( num / den );
	}
	
	double TorusVUUSymbol(double u, double v) {
		
		double m_tube_rad = 1., m_hole_rad = 2.;
		
		return ( ( TWO_PI / m_tube_rad )*( m_hole_rad + m_tube_rad*cos( TWO_PI*v ) )*sin( TWO_PI*v ) );
	}
	
	CurveTensor::CurveTensor() : m_uuu(&ZeroSymbol), m_uuv(&ZeroSymbol), m_uvv(&ZeroSymbol), 
		m_vuu(&ZeroSymbol), m_vuv(&ZeroSymbol), m_vvv(&ZeroSymbol) {
		/* Intentionally Empty */
	}
	
	CurveTensor::CurveTensor( char signalchar ) : CurveTensor() {
		
		//Default constructor sets all symbols to zero symbol, so only change non-zero ones
		switch ( signalchar ) {
			case 'S': m_uuv = &SphereUUVSymbol; m_vuu = &SphereVUUSymbol;
								break;
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
