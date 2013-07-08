123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
##==============================================================================

## ./test-lookup-table.c
## ./test-lookup-table

## ./test-count-num-bitsset
## /opt/local/bin/gcc-mp-4.7 -Wall -Wextra -Wno-unused-parameter -ggdb -DDEBUG -O0 -o test-count-num-bitsset test-count-num-bitsset.c

##---------------------------------
## COMPILER / LINKER SETTINGS ...

# CXX:=/usr/bin/g++-4.2
CC:=/opt/local/bin/gcc-mp-4.7
CXX:=/opt/local/bin/g++-mp-4.7

CPPFLAGS:=-I.

CXXFLAGS:=-Wall -Wextra -std=c++0x

CXXDEBUG:=-O0

LDFLAGS:=-L.
LOADLIBS:=

RMF:=/bin/rm -f
RMFR:=/bin/rm -fr

##------------------------------------------------------------------------------

## ./test-count-num-bitsset
PROGRAM := test-count-num-bitsset

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
