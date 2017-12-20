

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
			Step(Step* prev_step, const double length_walked, const double u, const double v) :
				m_prev_step(prev_step), m_length_walked(length_walked), m_u(u), m_v(v) {}
			
			/**
			 * Default Constructor
			 * Sets previous step to nullptr, length walked to zero and the point of the step to zero point
			 */
			Step() : m_prev_step(nullptr), m_length_walked(0), m_u(0), m_v(0) {}
			
			/**
			 * Access pointer to previous step.
			 */
			Step* PrevStep() const { return m_prev_step; }
			
			/**
			 * Access length walked to this step
			 */
			double LengthWalked() const { return m_length_walked; }
			
			/**
			 * Access point of step
			 */
			void StepPoint(double &u, double &v) const { u = m_u; v = m_v; return; }
			
			/**
			 * Set pointer to previous step
			 */
			void SetPrevStep(const Step* prev_step) { m_prev_step = prev_step; return; }
			
			/**
			 * Set length walked to this step
			 */
			void SetLengthWalked(const double length_walked) { m_length_walked = length_walked; return; }
			
			/**
			 * Set point of step
			 */
			void SetStepPoint(const double u, const double v) { m_u = u; m_v = v; return; }
			
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
