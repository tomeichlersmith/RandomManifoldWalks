

#ifndef MOSEY_RANDDOUBLE_HPP
#define MOSEY_RANDDOUBLE_HPP

#include <functional>
#include <random>

namespace MOSEY {

	/**
	 * RandDouble. A class to generate a uniform distribution of random reals.
	 */
	class RandDouble {
		public:
			/**
			 * Constructor.
			 * Requires entry of minimum a and maximum b
			 */
			RandDouble(double minimum, double maximum) :
				r( std::bind(
					std::uniform_real_distribution<>( minimum , maximum ),
					std::default_random_engine() ) ) {}
		
			/**
			 * Operator to return a random value from r
			 */
			double operator()() { return r(); }
		
		private:
			/**
			 * Function that is the uniform distribution bound to a generator.
			 * Outputs a value that is from the uniform distribution [minimum, maximum)
			 */
			std::function<double()> r;
	};
	
}

#endif
