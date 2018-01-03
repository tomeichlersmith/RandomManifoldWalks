
#include "../MOSEY/CurveTensor.hpp"

namespace MOSEY {
	
		CurveTensor::CurveTensor(ChristoffelSymbolPtr _uuu, ChristoffelSymbolPtr _uuv, ChristoffelSymbolPtr _uvv,
								ChristoffelSymbolPtr _vuu, ChristoffelSymbolPtr _vuv, ChristoffelSymbolPtr _vvv) :
								uuu(_uuu), uuv(_uuv), uvv(_uvv), vuu(_vuu), vuv(_vuv), vvv(_vvv) {}
	
		CurveTensor::UUU(double u, double v) const { return uuu(u,v); }
		CurveTensor::UUV(double u, double v) const { return uuv(u,v); }
		CurveTensor::UVV(double u, double v) const { return uvv(u,v); }
		CurveTensor::VUU(double u, double v) const { return vuu(u,v); }
		CurveTensor::VUV(double u, double v) const { return vuv(u,v); }
		CurveTensor::VVV(double u, double v) const { return vvv(u,v); }
	
	/**
	 * The Zero function in the Christoffel symbol type.
	 */
	ChristoffelSymbolPtr ZeroSymbol(double u, double v) { return 0; }

	/**
	 * The zero curvature tensor in the CurveTensor class.
	 */
	CurveTensor ZeroTensor( ZeroSymbol , ZeroSymbol , ZeroSymbol , ZeroSymbol , ZeroSymbol , ZeroSymbol );
	
}
