

#ifndef MOSEY_CURVETENSOR_HPP
#define MOSEY_CURVETENSOR_HPP

namespace MOSEY {

	/**
	 * Defining type of function that is considered a Christoffel Symbol
	 */
	typedef double (*ChristoffelSymbolPtr)(const double u, const double v);

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
									ChristoffelSymbolPtr _vuu, ChristoffelSymbolPtr _vuv, ChristoffelSymbolPtr _vvv);
		
			double UUU(const double u, const double v) const;
			double UUV(const double u, const double v) const;
			double UVV(const double u, const double v) const;
			double VUU(const double u, const double v) const;
			double VUV(const double u, const double v) const;
			double VVV(const double u, const double v) const;
		
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
	 * NOT DEFINED
	 */
	ChristoffelSymbolPtr ZeroSymbol;

	/**
	 * The zero curvature tensor in the CurveTensor class.
	 */
	CurveTensor ZeroTensor( ZeroSymbol , ZeroSymbol , ZeroSymbol , ZeroSymbol , ZeroSymbol , ZeroSymbol );
}

#endif