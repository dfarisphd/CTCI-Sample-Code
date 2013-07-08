##------------------------------------------------------------------------------

# CXX:=/usr/bin/g++-4.2
CXX:=/opt/local/bin/g++-mp-4.7

CPPFLAGS:=-I.

CXXFLAGS:=-Wall -Wextra -std=c++0x

CXXDEBUG:=-O0

LDFLAGS:=-L.
LOADLIBS:=

RMF:=/bin/rm -f
RMFR:=/bin/rm -fr

##------------------------------------------------------------------------------

PROGRAM:=TestDriver

SOURCES:=TestDriver.cpp

OBJS:=TestDriver.o

INCLUDES:=STLUtils.h

.PHONY: all
all: TestDriver

##------------------------------------------------------------------------------

$(PROGRAM).o: $(SOURCES) $(INCLUDES)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $(CXXDEBUG) -o $(PROGRAM).o $(PROGRAM).cpp

$(PROGRAM): $(PROGRAM).o
	$(CXX) $(LDFLAGS) -o $(PROGRAM) $(PROGRAM).o $(LOADLIBS)

clean:
	$(RMF) $(OBJS)

clean_all: clean
	$(RMF) $(PROGRAM)

##------------------------------------------------------------------------------
