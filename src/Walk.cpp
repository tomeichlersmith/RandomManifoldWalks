
#include "../MOSEY/Walk.hpp"

namespace MOSEY {
	
	Walk::Walk() : 
		m_rand_gen(0,1), m_last(nullptr), m_step_length(1), m_total_length_walked(0), m_maximum_walk_length(100),
		m_escape_check(nullptr), m_stepper(nullptr) {
		/* Intentionally Empty */
	}
	
	Walk::Walk(const double step_length, EscapeCheckPtr escape_check, Stepper* stepper) :
		m_rand_gen(0,1), m_last(nullptr), m_step_length(step_length), m_total_length_walked(0), m_maximum_walk_length(100),
		m_escape_check(escape_check), m_stepper(stepper) {
		/*Intentionally Empty */
	}
	
	/*Walk::Walk(const Walk& a_walk) {
		//Copy constructor - have to think (FUCK)
	}*/
	
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
			u = 0;
			v = 0;
			escape_length = 0;
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
	
	bool Walk::Empty() const {
		return (m_last == nullptr);
	}
	
	void Walk::StepForward() {
		
		//Get starting point
		double u0, v0;
		m_last->StepPoint( u0 , v0 );
		
		//Get random starting angle
		double randdir = TWO_PI*m_rand_gen();
		
		//Declare ending point
		double u1, v1;
		
		//Make a step using member variable step length
		m_stepper->Forward( u0, v0 , randdir , m_step_length , u1 , v1 );
		
		//Increment total length walked
		m_total_length_walked += m_step_length;
		
		//Push new step onto the stack
		StepPtr newstep = new Step( m_last , m_total_length_walked , u1 , v1 );
		m_last = newstep;
		
		return;
	}
	
}
