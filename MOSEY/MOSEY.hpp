/**
 * Include file for package
 * Adds some entire package functions
 */


#include "CoordinateWrappers.hpp"
#include "CurveTensor.hpp"
#include "EscapeCheck.hpp"
#include "RandDouble.hpp"
#include "Step.hpp"
#include "Stepper.hpp"
#include "Walk.hpp"

#include <iostream>
#include <fstream> //data export to file
#include <string>

namespace MOSEY {
	
	/**
	 * Function to simulate numwalks walks on the sphere.
	 * Escape region is arctic circle centered on north pole with boundary at latitude pol_angle.
	 * Output given in latitudes and put into file at filepath.
	 * All walks started at south pole.
	 * @param steplen length of each step of walk
	 * @param pol_angle latitude of boundary of escape region given in radians
	 * @param filepath path to data storage file
	 * @param numwalks number of walks to simulate
	 */
	void SphereWalk( double steplen , double pol_ang , std::string filepath , int numwalks );
	
}
