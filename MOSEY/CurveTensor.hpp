

#ifndef MOSEY_CURVETENSOR_HPP
#define MOSEY_CURVETENSOR_HPP

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
									ChristoffelSymbolPtr _vuu, ChristoffelSymbolPtr _vuv, ChristoffelSymbolPtr _vvv);
		
			UUU(double u, double v) const;
			UUV(double u, double v) const;
			UVV(double u, double v) const;
			VUU(double u, double v) const;
			VUV(double u, double v) const;
			VVV(double u, double v) const;
		
		private:
			ChristoffelSymbolPtr uuu;
			ChristoffelSymbolPtr uuv;
			ChristoffelSymbolPtr uvv;
			ChristoffelSymbolPtr vuu;
			ChristoffelSymbolPtr vuv;
			ChristoffelSymbolPtr vvv;
	};

}

#endif
