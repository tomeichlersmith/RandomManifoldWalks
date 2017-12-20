

#ifndef MOSEY_ESCAPECHECKS_HPP
#define MOSEY_ESCAPECHECKS_HPP

namespace MOSEY {

	/**
	 * Defining type of function that will be used to check if a domain point is in an escape region.
	 */
	typedef bool (*EscapeCheckPtr)(double u, double v);
	
}

#endif
