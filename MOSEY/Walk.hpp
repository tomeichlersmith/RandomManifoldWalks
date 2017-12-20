
#ifndef MOSEY_WALK_HPP
#define MOSEY_WALK_HPP

#include "Step.hpp"

namespace MOSEY {
	/**
	 * Walk Class. Stack linked list, code copied heavily from Savitch 2009.
	 */
	class Walk {
		public:
			/**
			 * Default Constructor. Initializes empty stack, sets step length to one, and sets escape check to nullptr
			 */
			Walk();
			
			/**
			 * Preferred Constructor. Initializes empty stack and defines the escape check function and step length
			 */
			Walk(const double step_length, EscapeCheckPtr escape_check);
			
			/**
			 * Copy Constructor.
			 */
			Walk(const Walk& a_walk);
		
			/**
			 * Destructor. Avoiding memory leakage.
			 */
			~Walk();
		
			/**
			 * Add a new step to the walk and increment total_walk_length.
			 * New step is in random direction and is made from m_last.
			 */
			void stepforward();
		
			/**
			 * Remove a single step off the top of the stack and "return" the point and
			 * length to escape
			 */
			void stepbackward(double &u, double &v, double &escape_length);
		
			/**
			 * Utility function to tell if the stack is empty.
			 */
			bool empty() const;
			
		private:
			/**
			 * pointer to last step taken (serves role as top of stack)
			 */
			StepPtr m_last;
			
			/**
			 * length that each step should be on the manifold
			 */
			double m_step_length;
			
			/**
			 * total length walked to get to m_last
			 */
			double m_total_length_walked;
			
			/**
			 * function defining if the walk has entered the escape region
			 */
			EscapeCheckPtr m_escape_check;
	};
	
}

#endif
