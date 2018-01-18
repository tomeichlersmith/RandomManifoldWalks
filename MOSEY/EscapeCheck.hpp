

#ifndef MOSEY_ESCAPECHECK_HPP
#define MOSEY_ESCAPECHECK_HPP

#include <cmath>
#include <vector>
#include <iostream> //Funcitonal Checks

#include "Step.hpp"

namespace MOSEY {

	/**
	 * typedef function pointer to be used as escape checks
	 */
	typedef bool (*EscapeCheckPtr)(std::vector<double> parameters, StepPtr step);
	
	namespace EscapeCheck {
	
		/**
		 * Defines escape region as a circle and if step is further away from
		 * the center than the given radius, then returns true.
		 * @param parameters list of the form { r , u , v } where r is the radius, u is the 
		 *  u coordinate of the center, and v is the v coordinate
		 */
		bool OutsideCircle(std::vector<double> parameters, StepPtr step);
		
		/**
		 * Defines escape region as the area in between concentric circles.
		 * Calculates step's distance from the center of the cirlces and then
		 * returns true if it is in between the two radii
		 * @param parameters list of the form { r , R , u , v } where r is the inner radius,
		 *  R is the outer radius, and (u,v) is the center of the circles
		 */
		bool CircleRing(std::vector<double> parameters, StepPtr step);
		
		/**
		 * Defines escape region as the area 'above' a threshhold v-coordinate.
		 * Intented to be used on the Sphere (with usual chart) in which this escape
		 * region is a circle around the 'south' pole (the pole with v = pi)
		 * @param parameters list of the form { vthresh } where vthresh is the minimum v
		 *  coordinate to be in the escape region
		 */
		bool VThresh(std::vector<double> parameters, StepPtr step);
	
	} //namespace EscapeCheck
	
}

#endif
