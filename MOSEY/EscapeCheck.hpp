

#ifndef MOSEY_ESCAPECHECK_HPP
#define MOSEY_ESCAPECHECK_HPP

#include <cmath>
#include <vector>

#include "Step.hpp"

namespace MOSEY {

	/**
	 * typedef function pointer to be used as escape checks
	 */
	typedef bool (*EscapeCheckPtr)(std::vector<double> parameters, StepPtr step);
	
	
}

#endif
