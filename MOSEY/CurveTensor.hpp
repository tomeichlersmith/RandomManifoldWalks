

#ifndef MOSEY_CURVETENSOR_HPP
#define MOSEY_CURVETENSOR_HPP

#include <cmath>

namespace MOSEY {
	
	const long double PI = M_PI;
	const long double TWO_PI = 2*PI;
	
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
			CurveTensor(ChristoffelSymbolPtr uuu, ChristoffelSymbolPtr uuv, ChristoffelSymbolPtr uvv,
									ChristoffelSymbolPtr vuu, ChristoffelSymbolPtr vuv, ChristoffelSymbolPtr vvv);
			
			/**
			 * Copy Constructor
			 */
			CurveTensor( const CurveTensor &ct );
		
			double UUU(const double u, const double v) const;
			double UUV(const double u, const double v) const;
			double UVV(const double u, const double v) const;
			double VUU(const double u, const double v) const;
			double VUV(const double u, const double v) const;
			double VVV(const double u, const double v) const;
		
		private:
			ChristoffelSymbolPtr m_uuu;
			ChristoffelSymbolPtr m_uuv;
			ChristoffelSymbolPtr m_uvv;
			ChristoffelSymbolPtr m_vuu;
			ChristoffelSymbolPtr m_vuv;
			ChristoffelSymbolPtr m_vvv;
	};
	
	/**
	 * The zero function in the Christoffel symbol type.
	 */
	double ZeroSymbol(const double u, const double v);

	/**
	 * The zero curvature tensor in the CurveTensor class (plane)
	 */
	CurveTensor PlaneTensor( &ZeroSymbol , &ZeroSymbol , &ZeroSymbol , 
													 &ZeroSymbol , &ZeroSymbol , &ZeroSymbol );
	
	/**
	 * The uuv christoffel symbol for the sphere
	 */
	double ChrisSym_SphereUUV(const double u, const double v);
	
	/**
	 * The vuu christoffel symbol for the sphere
	 */
	double ChrisSym_SphereVUU(const double u, const double v);
	
	/**
	 * The curvature tensor for the sphere parameterized by
	 * (u,v) -> ( cos(2pi u) sin(pi v) , sin(2pi u) sin(pi v) , cos(pi v) )
	 */
	CurveTensor SphereTensor( &ZeroSymbol , &ChrisSym_SphereUUV , &ZeroSymbol ,
														&ChrisSym_SphereVUU , &ZeroSymbol , &ZeroSymbol );
}

#endif
