

#ifndef MOSEY_ESCAPECHECK_OUTSIDECIRCLE_HPP
#define MOSEY_ESCAPECHECK_OUTSIDECIRCLE_HPP

#include "../EscapeCheck.hpp"

namespace MOSEY {

	/**
	 * Returns true if input step is outside the defined circle, otherwise returns false.
	 */
	class OutsideCircle : public EscapeCheck {
		public:
			/**
			 * Default Constructor. Unit circle centered at origin
			 */
			OutsideCircle();
			
			/**
			 * General Constructor.
			 */
			OutsideCircle(double radius, double ucenter, double vcenter);
			
			/**
			 * Set radius of escape circle
			 */
			void SetRadius(double radius);
			
			/**
			 * Set Center of escape circle
			 */
			void SetCenter(double u, double v);
			
			/**
			 * Member function to perform escape check
			 */
			bool IsFree(StepPtr step) const;
		
		private:
			double m_radius; //* Radius of circle
			double m_ucenter; //* u coordinate of center
			double m_vcenter; //* v coordinate of center
	};
	
}

#endif
