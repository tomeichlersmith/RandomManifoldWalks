

#ifndef MOSEY_CURVETENSOR_HPP
#define MOSEY_CURVETENSOR_HPP

#include <cmath>

namespace MOSEY {
	
	const long double PI = M_PI;
	const long double TWO_PI = 2*PI;
	
	/**
	 * Christoffel Symbol function type
	 */
	typedef double (*ChristoffelSymbolPtr)(double,double);
	
	/**
	 * The zero funciton in Christoffel Symbol structure.
	 */
	double ZeroSymbol(double u, double v);
	
	/**
	 * Sphere UUV Christoffel Symbol.
	 * pi*cot( pi*v )
	 */
	double SphereUUVSymbol(double u, double v);
	
	/**
	 * Sphere VUU Christoffel Symbol.
	 * -2*pi*sin( 2*pi*v )
	 */
	double SphereVUUSymbol(double u, double v);
	
	/**
	 * Torus UUV Christoffel Symbol.
	 * (-2*pi*r*sin( 2*pi*v ))/(R+r*cos( 2*pi*v ))
	 */
	double TorusUUVSymbol(double u, double v);
	
	/**
	 * Torus VUU Christoffel Symbol.
	 * (2*pi/r)*(R+r*cos( 2*pi*v )*sin( 2*pi*v )
	 */
	double TorusVUUSymbol(double u, double v);
	
	enum Manifold { Plane , Sphere , Torus };
	
	/**
	 * Curvature Tensor class. A short class that stores the Christoffel symbols for a two dimensional manifold.
	 * Assumes Curvature Tensor is symmetric (i.e. uuv = uvu and vuv = vvu)
	 */
	class CurveTensor {
		public:
			/**
			 * Default Constructor. Sets all Christoffel Symbols to Zero Symbol (plane).
			 */
			CurveTensor();
			
			/**
			 * Preferred Constructor. Sets Christoffel Symbols depending on input Manifold.
			 */
			CurveTensor( Manifold m );
			
			/**
			 * General Constructor.
			 */
			CurveTensor( ChristoffelSymbolPtr uuu, ChristoffelSymbolPtr uuv, ChristoffelSymbolPtr uvv,
									 ChristoffelSymbolPtr vuu, ChristoffelSymbolPtr vuv, ChristoffelSymbolPtr vvv );
			
			double UUU(double u, double v) const;
			double UUV(double u, double v) const;
			double UVV(double u, double v) const;
			double VUU(double u, double v) const;
			double VUV(double u, double v) const;
			double VVV(double u, double v) const;
		
		private:
			ChristoffelSymbolPtr m_uuu;
			ChristoffelSymbolPtr m_uuv;
			ChristoffelSymbolPtr m_uvv;
			ChristoffelSymbolPtr m_vuu;
			ChristoffelSymbolPtr m_vuv;
			ChristoffelSymbolPtr m_vvv;
	};
	
}

#endif
