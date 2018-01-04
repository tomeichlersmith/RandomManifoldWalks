
#include "../MOSEY/CurveTensor.hpp"

namespace MOSEY {
	
	CurveTensor::CurveTensor(ChristoffelSymbolPtr _uuu, ChristoffelSymbolPtr _uuv, ChristoffelSymbolPtr _uvv,
							ChristoffelSymbolPtr _vuu, ChristoffelSymbolPtr _vuv, ChristoffelSymbolPtr _vvv) :
							m_uuu(_uuu), m_uuv(_uuv), m_uvv(_uvv), m_vuu(_vuu), m_vuv(_vuv), m_vvv(_vvv) {
		/* Intentionally Empty */
	}
	
	CurveTensor::CurveTensor( const CurveTensor &ct ) {
		
		this->m_uuu = ct.m_uuu;
		this->m_uuv = ct.m_uuv;
		this->m_uvv = ct.m_uvv;
		this->m_vuu = ct.m_vuu;
		this->m_vuv = ct.m_vuv;
		this->m_vvv = ct.m_vvv;
		
	}

	double CurveTensor::UUU(const double u, const double v) const { return m_uuu(u,v); }
	double CurveTensor::UUV(const double u, const double v) const { return m_uuv(u,v); }
	double CurveTensor::UVV(const double u, const double v) const { return m_uvv(u,v); }
	double CurveTensor::VUU(const double u, const double v) const { return m_vuu(u,v); }
	double CurveTensor::VUV(const double u, const double v) const { return m_vuv(u,v); }
	double CurveTensor::VVV(const double u, const double v) const { return m_vvv(u,v); }
	
}
