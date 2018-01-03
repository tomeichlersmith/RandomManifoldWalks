

CXX = g++
DEBUG = -g
CXXFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFlAGS = -std=c++11 -Wall $(DEBUG)
INCDIR = MOSEY
OBJS = bin/Stepper.o bin/Walk.o

bin/libMOSEY.a : $(OBJS)
	ar -rc $@ $^

bin/Stepper.o : $(INCDIR)/Stepper.hpp src/Stepper.cpp $(INCDIR)/ChristoffelSymbols.hpp $(INCDIR)/CoordinateWrappers.hpp
	$(CXX) $(CXXFLAGS) src/Stepper.cpp -o $@

bin/Walk.o : $(INCDIR)/Walk.hpp src/Walk.cpp $(INCDIR)/RandDouble.hpp $(INCDIR)/Stepper.hpp $(INCDIR)/Step.hpp

directories :
	mkdir -p bin

clean :
	rm -r bin/*
