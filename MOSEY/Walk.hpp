
#ifndef MOSEY_WALK_HPP
#define MOSEY_WALK_HPP

#include <iostream> //Export
#include <cmath> //sqrt and atan

#include "Stepper.hpp"
#include "Step.hpp"
#include "EscapeCheck.hpp"
#include "RandDouble.hpp"
#include "CurveTensor.hpp" //Definition of TWO_PI

namespace MOSEY {
	
	/**
	 * enum to specify how data is to be exported
	 * Radius outputs std::sqrt( u*u + v*v )
	 * VCoord outputs only the v coordinate
	 * UV outputs both u and v
	 */
	enum ExportType { Radius , PolarAng , UV };
	
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
			 * General Constructor. Initializes empty stack and defines the escape check function and step length
			 */
			Walk(const double step_length, EscapeCheckPtr escape_check, std::vector<double> check_parameters, Stepper stepper);
			
			/**
			 * Preferred Constructor. Initializes empty stack and defines member variables
			 * that depend on the manifold depending on Manifold m
			 */
			Walk(Manifold m);
			
			/**
			 * Copy Constructor.
			 */
			Walk(const Walk& a_walk);
		
			/**
			 * Destructor. Avoiding memory leakage.
			 */
			~Walk();
			
			/**
			 * Assignment Operator.
			 */
			Walk& operator=(const Walk& rhs);
			
			/**
			 * Set maximum walk length that will be allowed
			 */
			void SetMaxWalkLength(const double max_walk_length);
			
			/**
			 * Set the length of each step of the random walk
			 */
			void SetStepLength(const double step_length);
			
			/**
			 * Set the escape region
			 */
			void SetEscapeRegion(EscapeCheckPtr escape_check, std::vector<double> check_parameters);
			
			/**
			 * Continues to step forward until the escape check returns true begining at input point
			 */
			void Wander(const double u, const double v);
			
			/**
			 * Exports what has been walked to ostream using StepBackward
			 * @param outs ostream that is already connected to destination
			 * @param type ExportType that specifies how data should be written to file
			 * @sa ExportType
			 */
			void Export( std::ostream& outs , ExportType type );
			
			int MaxWalkCount() const;
			
		private:
			
			RandDouble m_randangle; //* random number generator
			
			StepPtr m_last; //* pointer to last step taken (serves role as top of stack)
			
			double m_step_length; //* length that each step should be on the manifold
			
			double m_total_length_walked; //* total length walked to get to m_last
			
			double m_maximum_walk_length; //* maximum walk length (to avoid infinite loops)
			
			int m_maxlen_counter; //* counts the number of walks that have reached maximum walk length
			
			EscapeCheckPtr m_escape_check; //* function defining if the walk has entered the escape region
			
			std::vector<double> m_check_parameters; //* escape check function parameters (depends on the function)
			
			Stepper m_stepper; //* Stepper class instance that contains the necessary manifold information
			
			/**
			 * Add a new step to the walk and increment total_walk_length.
			 * New step is in random direction and is made from m_last.
			 */
			void StepForward();
			
			/**
			 * Remove a single step off the top of the stack and "return" the point and
			 * length to escape
			 */
			void StepBackward(double &u, double &v, double &escape_length);
			
			/**
			 * Utility function to tell if the stack is empty.
			 */
			bool Empty() const;
	};
	
}

#endif
