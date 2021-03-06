# RandomManifoldWalks
Mathematica and related files on performing random walks on various (simple and nice) manifolds. Mathematica is used to confirm the implementation written in C++ in order to obtain higher efficiency. It is suggested that each new manifold is compared to several walks done in Mathematica in order to maintain accuracy of the C++ package MOSEY.

----------------------------------------------------------------------------------------------------------------------------

Data Analysis and Plotting will be done in R while using a standard csv file to transfer the simulation data from the C++ program to R's ability to plot and process large data sets.

## Executables
These are being compiled and executed on a Linux machine, so several command line arguments may change if running on a different system.

#### SphereWalk
Compile: `make directories run/SphereWalk`
Run: `./run/SphereWalk lat nwalks steplen maxwalklen filename`
Inputs:
 - `lat`: polar angle of escape region boundary (in radians)
 - `nwalks`: number of walks to simulate
 - `steplen`: length of each step of the walks
 - `maxwalklen`: maximum walk length before exiting
 - `filename`: data storage filename

Plot Generation
*Requires the ggplot2 package*
Run: `Rscript --vanilla Sphere/PlotGen.R filename includeraw`
Inputs:
 - `filename` : data storage filename (same as provided to SphereWalk above)
 - `includeraw` : 'T' or 'F' to indicate whether to include raw data (T) or not (F)

#### PlaneWalk
Compile: `make directories run/PlaneWalk`
Run: `./run/PlaneWalk inner_rad outer_rad nwalks steplen maxwalklen filename`
Inputs:
 - `inner_rad`: inner radius for escape region boundary (set to zero or less to not have an inner circle)
 - `outer_rad`: outer radius for escape region boundary (must be larger than zero)
 - `nwalks`: number of walks to simulate
 - `steplen`: length of each step of the walks
 - `maxwalklen`: maximum walk length before exiting
 - `filename`: data storage filename

Plot Generation
Run: `Rscript --vanilla Plane/PlotGen.R filename includeraw`
Inputs:
	- `filename` : data storage filename (same as provided to PlaneWalk above)
	- `includeraw` : 'T' or 'F' to indicate whether to include raw data (T) or not (F)

#### PlaneCircleWalk
Compile: `make directories run/PlaneCircleWalk`
Run: `./run/PlaneCircleWalk side_len nwalks steplen maxwalklen filename`
Inputs:
 - `side_len`: length of side of square escape region centered at origin (should be positive and less than [\sqrt{2}] for square to be in circle walls)
 - `nwalks`: number of walks to simulate
 - `steplen`: length of each step of the walks
 - `maxwalklen`: maximum walk length before exiting
 - `filename`: data storage filename

#### Two-Dimensional Plot Generation (U and V Coordinates)
*requires the ggplot2 package*
Run: `Rscript --vanilla PlotGen2D.R datadir filename`
Inputs:
 - `datadir` : directory in which data is stored (with respect to the directory PlotGen2D.R is in
 - `filename` : name of file data is in, same as one given to walk generation script

## Classes for C++ Implementation:

RandGen: Uniform Random Real Generator
 - constructor
 - operator/function returning rand number

CurveTensor: storage of curve tensor in the form of public member functions 
 - Christoffel Symbols are stored as functions in namespace MOSEY::ChristoffelSymbol
 - Each manifold (with corresponding chart) has a defined signal character to input into constructor (e.g. S <=> sphere)
 - Default constructor is plane manifold (zero symbols)

CoordinateWrapper: functions that 'wrap' the parameter variables to keep them in the domain
 - Each wrapper is defined within the namespace CoordinateWrapper
 - Function that returns the coordinate within the correct range, wrapping the coordinate (either bouncing back or transporting)
 - Can be used to implement "walls" on the manifold (boundaries that a walk "bounces" off of, instead of wrapping to a different part of the domain)

EscapeCheck: functions that test if a given step is within an escape region (requires a paired parameters list)
 - Each escape check is defined within the namespace EscapeCheck
 - parameters list changes depending on type/shape of Escape Region
 - Escape checks are in terms of parameter space (u,v)

Stepper: Perform Geodesic Walk for given christoffel symbols / coordinate limits

Step: Node for Walk link list

Walk: Stack Linked List - pg 794 in Savitch
 - Formats Step Node, and total walk length before pushing
 - Rewind function that reads off points and distance to escape from list
 - Subtracts length walked from total walk length when reading back steps

