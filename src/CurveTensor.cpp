
#include "../MOSEY/CurveTensor.hpp"

namespace MOSEY {
	
	CurveTensor::CurveTensor(ChristoffelSymbolPtr _uuu, ChristoffelSymbolPtr _uuv, ChristoffelSymbolPtr _uvv,
							ChristoffelSymbolPtr _vuu, ChristoffelSymbolPtr _vuv, ChristoffelSymbolPtr _vvv) :
							uuu(_uuu), uuv(_uuv), uvv(_uvv), vuu(_vuu), vuv(_vuv), vvv(_vvv) {}

	CurveTensor::UUU(const double u, const double v) const { return uuu(u,v); }
	CurveTensor::UUV(const double u, const double v) const { return uuv(u,v); }
	CurveTensor::UVV(const double u, const double v) const { return uvv(u,v); }
	CurveTensor::VUU(const double u, const double v) const { return vuu(u,v); }
	CurveTensor::VUV(const double u, const double v) const { return vuv(u,v); }
	CurveTensor::VVV(const double u, const double v) const { return vvv(u,v); }
	
	ChristoffelSymbolPtr ZeroSymbol(const double u, const double v) { return 0; }
}
