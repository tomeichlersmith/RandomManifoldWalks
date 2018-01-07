
#include "../../MOSEY/EscapeCheck/OutsideCircle.hpp"

namespace MOSEY {
	
	OutsideCircle::OutsideCircle() : m_radius(1.), m_ucenter(0.), m_vcenter(0.) {
		/* Intentionally Empty */
	}
	
	OutsideCircle::OutsideCircle(double radius, double ucenter, double vcenter) :
		m_radius(radius), m_ucenter(ucenter), m_vcenter(vcenter) {
		/* Intentionally Empty */
	}
	
	void OutsideCircle::SetRadius(double r) {
		m_radius = r;
		return;
	}
	
	void OutsideCircle::SetCenter(double u, double v) {
		m_ucenter = u;
		m_vcenter = v;
		return;
	}
	
	bool OutsideCircle::IsFree(StepPtr step) const {
		//Get point of the step
		double u,v;
		step->StepPoint( u , v );
		
		//Calculate distance from step point to center
		double delu = (u - m_ucenter);
		double delv = (v - m_vcenter);
		double dist = std::sqrt( delu*delu + delv*delv );
		
		//Return true if (u,v) is further away from center than the radius
		return ( dist > m_radius );
	}
	
}
