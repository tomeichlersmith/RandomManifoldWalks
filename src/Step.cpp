
#include "../MOSEY/Step.hpp"

namespace MOSEY {
	
	Step::Step(Step* prev_step, const double length_walked, const double u, const double v) :
		m_prev_step(prev_step), m_length_walked(length_walked), m_u(u), m_v(v) {
		/* Intentionally Empty */ 
	}
	
	Step::Step() :
		m_prev_step(nullptr), m_length_walked(0), m_u(0), m_v(0) {
		/* Intentionally Empty */
	}
	
	Step* Step::PrevStep() const {
		return m_prev_step;
	}
	
	double Step::LengthWalked() const {
		return m_length_walked;
	}
	
	void Step::StepPoint(double &u, double &v) const {
		u = m_u;
		v = m_v;
		return;
	}
	
	void Step::SetPrevStep(const Step* prev_step) {
		m_prev_step = prev_step;
		return;
	}
	
	void Step::SetLengthWalked(const double length_walked) {
		m_length_walked = length_walked;
		return;
	}
	
	void Step::SetStepPoint(const double u, const double v) {
		m_u = u;
		m_v = v;
		return;
	}
	
}
