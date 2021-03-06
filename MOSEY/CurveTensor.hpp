

#ifndef MOSEY_CURVETENSOR_HPP
#define MOSEY_CURVETENSOR_HPP

#include <cmath>

namespace MOSEY {

	const long double PI = M_PI;
	const long double TWO_PI = 2*PI;

	namespace ChristoffelSymbol {

		/**
		 * The zero funciton in Christoffel Symbol structure.
		 */
		double Zero(double u, double v);

		/**
		 * Sphere UUV and VUV Christoffel Symbol.
		 * These symbols are the same in this coordinate patch
		 * -2u/(1+u*u+v*v)
		 */
		double SphereUUU_VUV(double u, double v);

		/**
		 * Sphere UUV and VVV Christoffel Symbol.
		 * These symbols are the same in this coordinate patch
		 * -2v/(1+u*u+v*v)
		 */
		double SphereUUV_VVV(double u, double v);

		/**
		 * Sphere UVV Christoffel Symbol.
		 * 2u/(1+u*u+v*v)
		 */
		double SphereUVV(double u, double v);

		/**
		 * Sphere VUU Christoffel Symbol.
		 * 2v/(1+u*u+v*v)
		 */
		double SphereVUU(double u, double v);

		/**
		 * Torus UUV Christoffel Symbol.
		 * (-2*pi*r*sin( 2*pi*v ))/(R+r*cos( 2*pi*v ))
		 */
		double TorusUUV(double u, double v);

		/**
		 * Torus VUU Christoffel Symbol.
		 * (2*pi/r)*(R+r*cos( 2*pi*v )*sin( 2*pi*v )
		 */
		double TorusVUU(double u, double v);

	} //namespace ChristoffelSymbol

	/**
	 * Christoffel Symbol function type
	 */
	typedef double (*ChristoffelSymbolPtr)(double,double);

	/**
	 * Manifold specification for formatted constructor
	 */
	enum Manifold { Plane , PlaneCircle, Sphere , Torus };

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
