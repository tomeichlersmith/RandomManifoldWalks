
#include "../MOSEY/EscapeCheck.hpp"

namespace MOSEY {
	
	EscapeCheck::EscapeCheck() {
		/* Intentionally Empty */
	}
	
	bool EscapeCheck::IsFree(StepPtr step) const {
		return false; //Should be redefined in Derived Class
	}
	
}
