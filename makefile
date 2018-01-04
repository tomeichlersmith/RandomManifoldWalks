

CXX = g++
DEBUG = -g
CXXFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFlAGS = -std=c++11 -Wall $(DEBUG)
INCDIR = MOSEY
OBJS = bin/CoordinateWrappers.o bin/CurveTensor.o bin/EscapeChecks.o bin/RandDouble.o bin/Step.o bin/Stepper.o bin/Walk.o

bin/libMOSEY.a : $(OBJS)
	ar -rc $@ $^

bin/CoordinateWrappers.o : src/CoordinateWrappers.cpp $(INCDIR)/CoordinateWrappers.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/CurveTensor.o : src/CurveTensor.cpp $(INCDIR)/CurveTensor.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/EscapeChecks.o : src/EscapeChecks.cpp $(INCDIR)/EscapeChecks.hpp $(INCDIR)/Step.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/RandDouble.o : src/RandDouble.cpp $(INCDIR)/RandDouble.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/Step.o : src/Step.cpp $(INCDIR)/Step.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/Stepper.o : src/Stepper.cpp $(INCDIR)/Stepper.hpp $(INCDIR)/CurveTensor.hpp $(INCDIR)/CoordinateWrappers.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

bin/Walk.o : src/Walk.cpp $(INCDIR)/Walk.hpp $(INCDIR)/RandDouble.hpp $(INCDIR)/Stepper.hpp $(INCDIR)/Step.hpp $(INCDIR)/EscapeChecks.hpp
	$(CXX) $(CXXFLAGS) $< -o $@

directories :
	mkdir -p bin

clean :
	rm -r bin/*
