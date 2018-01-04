

#ifndef MOSEY_STEP_HPP
#define MOSEY_STEP_HPP

namespace MOSEY {

	/**
	 * Step Class. Node class for Walk link list.
	 * Stores the point of step, length walked to get to that point,
	 * and a pointer to the previous step.
	 */
	class Step {
		public:
			/**
			 * Preferred Constructor
			 */
			Step(Step* prev_step, const double length_walked, const double u, const double v);
			
			/**
			 * Default Constructor
			 * Sets previous step to nullptr, length walked to zero and the point of the step to zero point
			 */
			Step();
			
			/**
			 * Access pointer to previous step.
			 */
			Step* PrevStep() const;
			
			/**
			 * Access length walked to this step
			 */
			double LengthWalked() const;
			
			/**
			 * Access point of step
			 */
			void StepPoint(double &u, double &v) const;
			
			/**
			 * Set pointer to previous step
			 */
			void SetPrevStep(Step* prev_step);
			
			/**
			 * Set length walked to this step
			 */
			void SetLengthWalked(const double length_walked);
			
			/**
			 * Set point of step
			 */
			void SetStepPoint(const double u, const double v);
			
		private:
			/**
			 * Pointer to previous step
			 */
			Step* m_prev_step;
			
			/**
			 * Length of walk to this step
			 */
			double m_length_walked;
			
			/**
			 * Coordinate Point of step
			 */
			double m_u, m_v;
	};
	
	typedef Step* StepPtr;
}

#endif
