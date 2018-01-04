
#ifndef MOSEY_WALK_HPP
#define MOSEY_WALK_HPP

#include "Stepper.hpp"
#include "Step.hpp"
#include "EscapeChecks.hpp"
#include "RandDouble.hpp"
#include "CurveTensor.hpp" //Definition of TWO_PI

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
			Walk(const double step_length, EscapeCheckPtr escape_check, Stepper* stepper);
			
			/**
			 * Copy Constructor.
			 * NOT WRITTEN
			 */
			//Walk(const Walk& a_walk);
		
			/**
			 * Destructor. Avoiding memory leakage.
			 */
			~Walk();
			
			/**
			 * Set maximum walk length that will be allowed
			 */
			void SetMaxWalkLength(const double max_walk_length);
			
			/**
			 * Continues to step forward until the escape check returns true begining at input point
			 */
			void Wander(const double u, const double v);
			
			/**
			 * Remove a single step off the top of the stack and "return" the point and
			 * length to escape
			 */
			void StepBackward(double &u, double &v, double &escape_length);
			
		private:
			
			/**
			 * Random number generator for direction
			 */
			RandDouble m_rand_gen;
			
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
			 * maximum walk length (to avoid infinite loops)
			 */
			double m_maximum_walk_length;
			
			/**
			 * function defining if the walk has entered the escape region
			 */
			EscapeCheckPtr m_escape_check;
			
			/**
			 * Pointer to Stepper class instance that contains the necessary manifold information
			 */
			Stepper* m_stepper;
			
			/**
			 * Utility function to tell if the stack is empty.
			 */
			bool Empty() const;
			
			/**
			 * Add a new step to the walk and increment total_walk_length.
			 * New step is in random direction and is made from m_last.
			 */
			void StepForward();
	};
	
}

#endif
