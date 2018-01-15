

#ifndef MOSEY_RANDDOUBLE_HPP
#define MOSEY_RANDDOUBLE_HPP

#include <functional>
#include <random>
#include <ctime>

namespace MOSEY {

	/**
	 * RandDouble. A class to generate a uniform distribution of random reals.
	 */
	class RandDouble {
		public:
			/**
			 * General Constructor.
			 * Requires entry of minimum and maximum
			 */
			RandDouble(const double minimum, const double maximum);
			
			/**
			 * Default Constructor.
			 * Sets minimum to 0 and maximum to 1
			 */
			RandDouble();
		
			/**
			 * Operator to return a random value from r
			 */
			double operator()();
		
		private:
			/**
			 * Function that is the uniform distribution bound to a generator.
			 * Outputs a value that is from the uniform distribution [minimum, maximum)
			 */
			std::function<double()> r;
	};
	
}

#endif
