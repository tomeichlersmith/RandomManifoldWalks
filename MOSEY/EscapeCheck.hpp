

#ifndef MOSEY_ESCAPECHECK_HPP
#define MOSEY_ESCAPECHECK_HPP

#include "Step.hpp"

namespace MOSEY {

	/**
	 * Defining class to be base class for all Escape Checks.
	 */
	class EscapeCheck {
		public:
			/**
			 * Default Constructor.
			 */
			EscapeCheck();
			
			/**
			 * Member function to perform escape check
			 */
			virtual bool IsFree(StepPtr step) const;
		
		private:
			// parameters of an escape check will be private member variables set by constructor
	};
	
}

#endif
