

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
	
	/**
	 * Defines escape region as a circle and if step is further away from
	 * the center than the given radius, then returns true.
	 * @param parameters list of the form { r , u , v } where r is the radius, u is the 
	 *  u coordinate of the center, and v is the v coordinate
	 */
	bool OutsideCircle(std::vector<double> parameters, StepPtr step);
	
}

#endif
