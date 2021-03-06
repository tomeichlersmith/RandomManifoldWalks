
#include "../MOSEY/Walk.hpp"

namespace MOSEY {

	Walk::Walk() :
		m_randangle(0,TWO_PI), m_last(nullptr), m_step_length(1), m_total_length_walked(0), m_maximum_walk_length(100),
		m_maxlen_counter(0), m_escape_check(nullptr), m_check_parameters(), m_stepper() {
		/* Intentionally Empty */
	}

	Walk::Walk(const double step_length, EscapeCheckPtr escape_check, std::vector<double> check_parameters, Stepper stepper) :
		m_randangle(0,TWO_PI), m_last(nullptr), m_step_length(step_length), m_total_length_walked(0), m_maximum_walk_length(100),
		m_maxlen_counter(0), m_escape_check(escape_check), m_check_parameters(check_parameters), m_stepper(stepper) {
		/*Intentionally Empty */
	}

	Walk::Walk(Manifold m) :
		m_randangle(0,TWO_PI), m_last(nullptr), m_step_length(1), m_total_length_walked(0), m_maximum_walk_length(100),
		m_maxlen_counter(0), m_escape_check(nullptr), m_check_parameters(), m_stepper(m,10) {
		/* Intentionally Empty */
	}

	Walk::Walk(const Walk& a_walk) : Walk() {

		*this = a_walk;

	}

	Walk::~Walk() {
		double u,v,len;
		while ( !Empty() ) {
			StepBackward( u , v , len ); //StepBackward calls delete
		}
	}

	Walk& Walk::operator=(const Walk& rhs) {

		if ( this != &rhs ) {

			this->m_step_length = rhs.m_step_length;
			this->m_total_length_walked = rhs.m_total_length_walked;
			this->m_maximum_walk_length = rhs.m_maximum_walk_length;
			this->m_maxlen_counter = rhs.m_maxlen_counter;
			this->m_escape_check = rhs.m_escape_check;
			this->m_check_parameters = rhs.m_check_parameters;
			this->m_stepper = rhs.m_stepper;

			//Copy of a_walk stack
			if ( !rhs.Empty() ) {
				StepPtr scroll = rhs.m_last;
				std::vector< StepPtr > stacklist;
				while( scroll->PrevStep() != nullptr ) {
					stacklist.push_back( scroll );
					scroll = scroll->PrevStep();
				}

				//Now push onto this stack
				//Need to procede in opposite order so final stack is in correct order
				double u,v,len;
				for (unsigned int i = stacklist.size(); i > 0; i--) {
					len = stacklist[i-1]->LengthWalked();
					stacklist[i-1]->StepPoint( u , v );

					//Push new step onto the stack
					StepPtr newstep = new Step( this->m_last , len , u , v );
					m_last = newstep;
				}
			} //rhs stack is nonempty
			else {
				this->m_last = nullptr;
			} //rhs stack is empty

		}

		return *this;
	}

	void Walk::SetMaxWalkLength(const double max_walk_length) {
		m_maximum_walk_length = max_walk_length;
		return;
	}

	void Walk::SetStepLength(const double step_length) {
		m_step_length = step_length;
		return;
	}

	void Walk::SetEscapeRegion(EscapeCheckPtr escape_check, std::vector<double> check_parameters) {
		m_escape_check = escape_check;
		m_check_parameters = check_parameters;
		return;
	}

	void Walk::Wander(const double u, const double v) {

		if ( Empty() ) {
			//Reset total length walked to zero
			m_total_length_walked = 0.;

			//push starting point with begining total walk length
			m_last = new Step(nullptr, m_total_length_walked, u, v);

			while ( !m_escape_check( m_check_parameters , m_last ) and m_total_length_walked < m_maximum_walk_length ) {
				StepForward();
			} //walking until escape

			if ( !m_escape_check( m_check_parameters , m_last) ) {
				std::cout << "WARNG:\tWalk did not escape. Erasing Walk.\n";

				m_maxlen_counter++;

				double u,v,len;
				while ( !Empty() ) {
					StepBackward( u , v , len );
				}

			} //walk ended but did not escape

		} //stack is empty, can perform new walk
		else {
			std::cout << "ERROR:\tWalk stack nonempty. Walk::StepBackward until empty." << std::endl;
		}

		return;
	}

	void Walk::Export( std::ostream& outs , ExportType type ) {

		double u,v,len;

		while ( !Empty() ) {

			StepBackward( u , v , len );

			switch ( type ) {
				case ExportType::Radius :
					outs << sqrt( u*u + v*v );
					break;
				case ExportType::PolarAng :
					outs << 2*atan( 1/sqrt( u*u + v*v ) );
					break;
				case ExportType::FirstQuad :
					outs << fabs(u) << "," << fabs(v);
					break;
				default :
					outs << u << "," << v;
					break;
			}

			outs << "," << len << std::endl;

		}

		return;
	}

	int Walk::MaxWalkCount() const {
		return ( m_maxlen_counter );
	}

	void Walk::StepForward() {

		//Get starting point
		double u0, v0;
		m_last->StepPoint( u0 , v0 );

		//Get random starting angle
		double randdir = m_randangle();

		//Declare ending point
		double u1, v1;

		//Make a step using member variable step length
		m_stepper.Forward( u0 , v0 , randdir , m_step_length , u1 , v1 );

		//Increment total length walked
		m_total_length_walked += m_step_length;

		//Push new step onto the stack
		StepPtr newstep = new Step( m_last , m_total_length_walked , u1 , v1 );
		m_last = newstep;

		//Functional Check
		//std::cout << u0 << " " << v0 << '\t' << u1 << " " << v1 << std::endl;

		return;
	}

	void Walk::StepBackward(double &u, double &v, double &escape_length) {

		if ( Empty() ) {
			std::cout << "ERROR:\tWalk stack empty. No steps to back-track." << std::endl;
		}
		else {
			//Get data from last step
			m_last->StepPoint( u , v );
			escape_length = m_total_length_walked - m_last->LengthWalked();

			//Delete last step
			StepPtr tempstep;
			tempstep = m_last;
			m_last = m_last->PrevStep();

			delete tempstep;
		}

		return;
	}

	bool Walk::Empty() const {
		return (m_last == nullptr);
	}

}
