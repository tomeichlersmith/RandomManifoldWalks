

#ifndef MOSEY_ESCAPECHECKS_HPP
#define MOSEY_ESCAPECHECKS_HPP

#include "Step.hpp"

namespace MOSEY {

	/**
	 * Defining type of function that will be used to check if a domain point is in an escape region.
	 * Return true if step is in the escape region (has escaped) and false otherwise
	 */
	typedef bool (*EscapeCheckPtr)(StepPtr step);
	
}

#endif
