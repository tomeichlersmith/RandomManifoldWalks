

CXX = g++
DEBUG = -g
CXXFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)
INCDIR = MOSEY
OBJS = bin/CoordinateWrappers.o bin/CurveTensor.o bin/EscapeCheck.o bin/RandDouble.o bin/Step.o bin/Stepper.o bin/Walk.o

all : run/SphereWalk

run/test : test.cpp bin/libMOSEY.a
	$(CXX) $(LFLAGS) $^ -o $@

run/SphereWalk : Sphere/WalkGen.cpp bin/libMOSEY.a
	$(CXX) $(LFLAGS) $^ -o $@

bin/libMOSEY.a : $(OBJS)
	ar -rc $@ $^

bin/CoordinateWrappers.o : src/CoordinateWrappers.cpp $(INCDIR)/CoordinateWrappers.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/CurveTensor.o : src/CurveTensor.cpp $(INCDIR)/CurveTensor.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/EscapeCheck.o : src/EscapeCheck.cpp $(INCDIR)/EscapeCheck.hpp $(INCDIR)/Step.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/RandDouble.o : src/RandDouble.cpp $(INCDIR)/RandDouble.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/Step.o : src/Step.cpp $(INCDIR)/Step.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/Stepper.o : src/Stepper.cpp $(INCDIR)/Stepper.hpp $(INCDIR)/CurveTensor.hpp $(INCDIR)/CoordinateWrappers.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/Walk.o : src/Walk.cpp $(INCDIR)/Walk.hpp $(INCDIR)/RandDouble.hpp $(INCDIR)/Stepper.hpp $(INCDIR)/Step.hpp $(INCDIR)/EscapeCheck.hpp $(INCDIR)/CurveTensor.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

directories :
	mkdir -p bin
	mkdir -p run
	mkdir -p Sphere/data

clean :
	rm -r bin/*
	rm -r run/*
