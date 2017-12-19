# RandomManifoldWalks
Mathematica and related files on performing random walks on various (simple and nice) manifolds.

## Classes for C++ Implementation:

RandGen: Complex Uniform Random Double Generator
 - constructor
 - operator/function returning rand number

typedef double (*ChristoffelSymbolPtr)(double u, double v)
 - Function that returns the value of a christoffel symbol at point (u,v)

typedef void (*CoordinateWrapperPtr)(double &u, double &v)
 - Function that returns the coordinate within the correct range, wrapping the coordinate (either bouncing back or transporting)
 
typedef bool (*EscapeCheckPtr)(double u, double v)
 - function to decide if point (u,v) is in the escape region

Stepper: Perform Geodesic Walk for given christoffel symbols / coordinate limits
 - CurveTensor curvetensor
 - int numsteps ⇒ number of steps to use in Runge-Kutta method (not number of steps in walk, this class performs a single step in the random walk)
 - CoordinateWrapperPtr coordwrap
 - Constructor
 - Forward(double u0, double v0, double direction, double steplen, double &u1, double &v1)

Step: Node for Walk link list
 - StepPtr previousstep
 - double length_walked
 - double u
 - double v

typedef Step* StepPtr

Walk: Stack Linked List - pg 794 in Savitch
 - StepPtr top
 - double total_walk_length
 - EscapeCheckPtr escapecheck
 - push function to push another step on top
 - pop function to pop another step off
 - Walk function that performs walk 
 - format Step Node, and total_walk_length before pushing
 - Rewind function that reads off points and distance to escape from list
 - Subtract length_walked from total_walk_length when poping
 - Constructor

Define default ChristoffelSymbolPtr (zero function)
Define default EscapeCheckPtr (...)

