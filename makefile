

CXX = g++
DEBUG = -g
CXXFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)
INCDIR = MOSEY
OBJS = bin/CoordinateWrappers.o bin/CurveTensor.o bin/Plane_CurveTensor.o bin/Sphere_CurveTensor.o bin/Torus_CurveTensor.o bin/EscapeCheck.o bin/OutsideCircle.o bin/RandDouble.o bin/Step.o bin/Stepper.o bin/Walk.o

test : test.cpp bin/libMOSEY.a
	$(CXX) $(LFLAGS) $^ -o $@

bin/libMOSEY.a : $(OBJS)
	ar -rc $@ $^

bin/CoordinateWrappers.o : src/CoordinateWrappers.cpp $(INCDIR)/CoordinateWrappers.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/CurveTensor.o : src/CurveTensor.cpp $(INCDIR)/CurveTensor.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/Plane_CurveTensor.o : src/CurveTensor/Plane.cpp $(INCDIR)/CurveTensor/Plane.hpp $(INCDIR)/CurveTensor.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/Sphere_CurveTensor.o : src/CurveTensor/Sphere.cpp $(INCDIR)/CurveTensor/Sphere.hpp $(INCDIR)/CurveTensor.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/Torus_CurveTensor.o : src/CurveTensor/Torus.cpp $(INCDIR)/CurveTensor/Torus.hpp $(INCDIR)/CurveTensor.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/EscapeCheck.o : src/EscapeCheck.cpp $(INCDIR)/EscapeCheck.hpp $(INCDIR)/Step.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/OutsideCircle.o : src/EscapeCheck/OutsideCircle.cpp $(INCDIR)/EscapeCheck/OutsideCircle.hpp $(INCDIR)/EscapeCheck.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/RandDouble.o : src/RandDouble.cpp $(INCDIR)/RandDouble.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/Step.o : src/Step.cpp $(INCDIR)/Step.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/Stepper.o : src/Stepper.cpp $(INCDIR)/Stepper.hpp $(INCDIR)/CurveTensor.hpp $(INCDIR)/CurveTensor/Plane.hpp $(INCDIR)/CoordinateWrappers.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/Walk.o : src/Walk.cpp $(INCDIR)/Walk.hpp $(INCDIR)/RandDouble.hpp $(INCDIR)/Stepper.hpp $(INCDIR)/Step.hpp $(INCDIR)/EscapeCheck.hpp $(INCDIR)/CurveTensor.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

directories :
	mkdir -p bin

clean :
	rm -r bin/* && rm test
