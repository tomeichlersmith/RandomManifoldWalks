
#include "../MOSEY/Stepper.hpp"

namespace MOSEY {
	
	Stepper::Stepper(CurveTensor curvetensor, int numsteps, CoordinateWrapperPtr coordwrap, bool issphere) :
		m_curvetensor(curvetensor), m_numsteps(numsteps), m_coordwrap(coordwrap), m_issphere(issphere) {
		/* Intentionally Empty */
	}
	
	Stepper::Stepper(Manifold m, int numsteps) :
		m_curvetensor(m), m_numsteps(numsteps), m_issphere(false) {
		
		switch (m) {
			case Manifold::PlaneSquare : m_coordwrap = &CoordinateWrapper::PlaneSquare;
								break;
			case Manifold::Sphere : m_coordwrap = &CoordinateWrapper::Sphere;
								m_issphere = true;
								break;
			case Manifold::Torus : m_coordwrap = &CoordinateWrapper::Torus;
								break;
			default : m_coordwrap = &CoordinateWrapper::Plane;
								m_numsteps = 1; //In the plane, one step of RK4 is exact solution
								break;
		}
		
	}
	
	Stepper::Stepper() : m_curvetensor(), m_numsteps(1), m_coordwrap(&CoordinateWrapper::Plane), m_issphere(false) {
		/* Intentionally Empty */
	}
		
	
	void Stepper::Forward(const double u0, const double v0, const double direction, const double steplen, double &u1, double &v1) const {
		
		//Declaring and Initializing variables that will be carried through Runge-Kutta
		double y[4] = { u0 , v0 , cos(direction) , sin(direction) };
		
		//Declaring useful variables
		double k1[4],y1[4],k2[4],y2[4],k3[4],y3[4],k4[4];
		
		//Step length for Runge-Kutta
		double h = steplen/m_numsteps;
		
		//Iterate through m_numsteps steps of RK4 approximation method
		for (int i = 0; i < m_numsteps; i++) {
			
			//Calculating k1 at y
			EvalSlope( y , k1 );
			
			//Calculating y1=y+k1*h/2
			for (unsigned int j = 0; j < 4; j++) {
				y1[j] = y[j] + (h/2)*k1[j];
			} //j: coordinate u,v,p,q
			
			//Calculating k2 at y1
			EvalSlope( y1 , k2 );
			
			//Calculating y2=y+k2*h/2
			for (unsigned int j = 0; j < 4; j++) {
				y2[j] = y[j] + (h/2)*k2[j];
			} //j: coordinate u,v,p,q
			
			//Calculating k3 at y2
			EvalSlope( y2 , k3 );
			
			//Calculating y3=y+k3*h
			for (unsigned int j = 0; j < 4; j++) {
				y3[j] = y[j] + h*k3[j];
			} //j: coordinate u,v,p,q
			
			//Calculating k4 at y3
			EvalSlope( y3 , k4 );
			
			//Stepping y forward
			for(unsigned int j = 0; j < 4; j++) {
				y[j] += (h/6)*( k1[j] + 2*k2[j] + 2*k3[j] + k4[j] );
			} //j: coordinate u,v,p,q
			
		} //i: steps in Runge-Kutta method
		
		u1 = y[0];
		v1 = y[1];
		
		//Make sure coordinates stay within domain of chart
		m_coordwrap( u1 , v1 );
		
		return;
	}
	
	void Stepper::EvalSlope(double y[], double k[]) const {
		
		k[0] = y[2];
		k[1] = y[3];
		k[2] = -m_curvetensor.UUU(y[0],y[1])*y[2]*y[2]-2*m_curvetensor.UUV(y[0],y[1])*y[2]*y[3]-m_curvetensor.UVV(y[0],y[1])*y[3]*y[3];
		k[3] = -m_curvetensor.VUU(y[0],y[1])*y[2]*y[2]-2*m_curvetensor.VUV(y[0],y[1])*y[2]*y[3]-m_curvetensor.VVV(y[0],y[1])*y[3]*y[3];
		
		//Funcitonal Check
		//for (int l = 0; l < 4; l++) { std::cout << k[l] << " "; } std::cout << std::endl;
		
		return;
	}
	
}
