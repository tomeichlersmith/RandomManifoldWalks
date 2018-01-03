
#include "../MOSEY/Walk.hpp"

namespace MOSEY {
	
	Walk::Walk() : 
		m_last(nullptr), m_total_length_walked(0), m_maximum_walk_length(100), m_step_length(1), m_escape_check(nullptr)
		{ /* Intentionally Empty */ }
	
	Walk::Walk(const double step_length, const double max_walk_length, EscapeCheckPtr escape_check) :
		Walk(), m_step_length(step_length), m_escape_check(escape_check)
		{ /*Intentionally Empty */ }
	
	Walk::Walk(const Walk& a_walk) {
		//Copy constructor - have to think (FUCK)
	}
	
	Walk::~Walk() {
		double u,v,len;
		while ( !Empty() ) {
			StepBackward( u , v , len ); //StepBackward calls delete
		}
	}
	
	void Walk::SetMaxWalkLength(const double max_walk_length) {
		m_maximum_walk_length = max_walk_length;
		return;
	}
	
	void Walk::Wander(const double u, const double v) {
		
		//push starting point with begining total walk length
		m_last = new Step(nullptr, m_total_length_walked, u, v);
		
		while ( !m_escape_check( m_last ) and m_total_length_walked < m_maximum_walk_length ) {
			StepForward();
		} //walking until escape
		
		return;
	}
	
	void Walk::StepBackward(double &u, double &v, double &escape_length) {
		if ( Empty() ) {
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
	
	void Walk::Empty() const {
		return (m_last == nullptr);
	}
	
	void Walk::StepForward() {
		//Randomly step using Stepper
	}
	
}
