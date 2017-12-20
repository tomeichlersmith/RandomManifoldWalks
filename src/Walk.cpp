
#include "../MOSEY/Walk.hpp"

namespace MOSEY {
	
	Walk::Walk() : 
		m_last(nullptr), m_total_length_walked(0), m_step_length(1), m_escape_check(nullptr)
		{ /* Intentionally Empty */ }
	
	Walk::Walk(const double step_length, EscapeCheckPtr escape_check) :
		Walk(), m_step_length(step_length), m_escape_check(escape_check)
		{ /*Intentionally Empty */ }
	
	Walk::Walk(const Walk& a_walk)
	
	Walk::~Walk() {
		double u,v,len;
		while ( !empty() ) {
			stepbackward( u , v , len ); //stepbackward calls delete
		}
	}
	
	void Walk::stepforward() {
		//Randomly step using Stepper
	}
	
	void Walk::stepbackward(double &u, double &v, double &escape_length) {
		if ( empty() ) {
			std::cout << "Error: No walk to trace back.\n"
			return;
		}
		
		//Get data from last step
		m_last->StepPoint( u , v );
		escape_length = m_total_length_walked - m_last->LengthWalked();
		
		//Delete last step
		StepPtr tempstep;
		tempstep = m_last;
		m_last = m_last->PrevStep();
		
		delete tempstep;
		
		return;
	}
	
	void Walk::empty() const {
		return (m_last = nullptr);
	}
	
}
