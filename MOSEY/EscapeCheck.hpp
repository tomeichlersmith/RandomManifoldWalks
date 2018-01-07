

#ifndef MOSEY_ESCAPECHECK_HPP
#define MOSEY_ESCAPECHECK_HPP

#include <cmath>

#include "Step.hpp"

namespace MOSEY {

	/**
	 * typedef function pointer to be used as escape checks
	 */
	typedef bool (*EscapeCheckPtr)(StepPtr step);
	
}

#endif
