
#include "../MOSEY/RandDouble.hpp"

namespace MOSEY {
	
	RandDouble::RandDouble(const double minimum, const double maximum) :
				r( std::bind(
					std::uniform_real_distribution<>( minimum , maximum ),
					std::default_random_engine( time(nullptr) ) ) ) {
		/* Intentionally Empty */
	}
	
	RandDouble::RandDouble() : RandDouble(0,1) {
		/* Intentionally Empty */
	}
	
	double RandDouble::operator()() {
		return r();
	}
	
}
