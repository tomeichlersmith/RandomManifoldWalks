

#ifndef MOSEY_CHRISTOFFELSYMBOLS_HPP
#define MOSEY_CHRISTOFFELSYMBOLS_HPP

namespace MOSEY {

	/**
	 * Defining type of function that is considered a Christoffel Symbol
	 */
	typedef double (*ChristoffelSymbolPtr)(double u, double v);

	/**
	 * Curvature Tensor class. A short class that stores the Christoffel symbols for a two dimensional manifold.
	 * Assumes Curvature Tensor is symmetric (i.e. uuv = uvu and vuv = vvu)
	 */
	class CurveTensor {
		public:
			/**
			 * Constructor
			 */
			CurveTensor(ChristoffelSymbolPtr _uuu, ChristoffelSymbolPtr _uuv, ChristoffelSymbolPtr _uvv,
									ChristoffelSymbolPtr _vuu, ChristoffelSymbolPtr _vuv, ChristoffelSymbolPtr _vvv) :
									uuu(_uuu), uuv(_uuv), uvv(_uvv), vuu(_vuu), vuv(_vuv), vvv(_vvv) {}
		
			UUU(double u, double v) const { return uuu(u,v); }
			UUV(double u, double v) const { return uuv(u,v); }
			UVV(double u, double v) const { return uvv(u,v); }
			VUU(double u, double v) const { return vuu(u,v); }
			VUV(double u, double v) const { return vuv(u,v); }
			VVV(double u, double v) const { return vvv(u,v); }
		
		private:
			ChristoffelSymbolPtr uuu;
			ChristoffelSymbolPtr uuv;
			ChristoffelSymbolPtr uvv;
			ChristoffelSymbolPtr vuu;
			ChristoffelSymbolPtr vuv;
			ChristoffelSymbolPtr vvv;
	};

	/**
	 * The Zero function in the Christoffel symbol type.
	 */
	ChristoffelSymbolPtr ZeroSymbol(double u, double v) { return 0; }

	/**
	 * The zero curvature tensor in the CurveTensor class.
	 */
	CurveTensor ZeroTensor( ZeroSymbol , ZeroSymbol , ZeroSymbol , ZeroSymbol , ZeroSymbol , ZeroSymbol );

}

#endif