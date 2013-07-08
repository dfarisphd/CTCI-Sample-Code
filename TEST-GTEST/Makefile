##------------------------------------------------------------------------------

## MAKE-Sample1-GTest.txt
## /Users/bueller/Dropbox/000-CTCI-Sample-Code/0BAK

## MAKE-Sample1-GTest.txt
## Makefile

## prime_tables.h
## sample1.cc
## sample1.h
## sample1.o
## sample1_unittest*
## sample1_unittest.cc
## sample1_unittest.o

##------------------------------------------------------------------------------
##------------------------------------------------------------------------------

## [..]$ /opt/local/bin/g++-mp-4.7 -L/opt/gtest/gtest-1.6.0-static-debug \
##       sample1.o sample1_unittest.o -o sample1_unittest -lgtest -lgtest_main
## [..]$ ./sample1_unittest 
## 
## Running main() from gtest_main.cc
## 
## [==========] Running 6 tests from 2 test cases.
## [----------] Global test environment set-up.
## [----------] 3 tests from FactorialTest
## [ RUN      ] FactorialTest.Negative
## [       OK ] FactorialTest.Negative (0 ms)
## [ RUN      ] FactorialTest.Zero
## [       OK ] FactorialTest.Zero (0 ms)
## [ RUN      ] FactorialTest.Positive
## [       OK ] FactorialTest.Positive (0 ms)
## [----------] 3 tests from FactorialTest (0 ms total)
## 
## [----------] 3 tests from IsPrimeTest
## [ RUN      ] IsPrimeTest.Negative
## [       OK ] IsPrimeTest.Negative (0 ms)
## [ RUN      ] IsPrimeTest.Trivial
## [       OK ] IsPrimeTest.Trivial (0 ms)
## [ RUN      ] IsPrimeTest.Positive
## [       OK ] IsPrimeTest.Positive (0 ms)
## [----------] 3 tests from IsPrimeTest (0 ms total)
## 
## [----------] Global test environment tear-down
## 
## [==========] 6 tests from 2 test cases ran. (0 ms total)
## [  PASSED  ] 6 tests.

##------------------------------------------------------------------------------

## I USE THE MAC-PORTS GCC PRODUCTS BECAUSE THEY HAVE BEEN MORE RECENT
## AND UP-TO-DATE VERSUS APPLE'S GCC AND NOW THE COMPLICATED CLANG/LLVM

# CXX:=/usr/bin/g++-4.2
CC  :=  /opt/local/bin/gcc-mp-4.7
CXX :=  /opt/local/bin/g++-mp-4.7

## GTEST --> /opt/gtest/gtest-1.6.0/include
## /opt/gtest/gtest-1.6.0-build-cmake-gui-makefiles-static-debug
## /opt/gtest/gtest-1.6.0-build-cmake-gui-makefiles-static-debug/include

GTEST_ROOT := /opt/gtest/gtest-1.6.0
GTEST_INCLUDE := /opt/gtest/gtest-1.6.0/include
GTEST_BUILD_STATIC := /opt/gtest/gtest-1.6.0-build-cmake-gui-makefiles-static-debug
GTEST_BUILD_INCLUDE := /opt/gtest/gtest-1.6.0-build-cmake-gui-makefiles-static-debug/include

LOCAL_INCLUDE := -I.
INCLUDES := $(LOCAL_INCLUDE) $(GTEST_BUILD_INCLUDE)

CPPFLAGS := $(INCLUDES)

## CXXFLAGS := -Wall -Wextra -std=c++0x
CCFLAGS := -Wall -Wextra -Wno-unused-parameters
CXXFLAGS := -Wall -Wextra -Wno-unused-parameters

CXXDEBUG:=-ggdb -O0

LDFLAGS:=-L. -L/opt/gtest/gtest-1.6.0-build-cmake-gui-makefiles-static-debug
LOADLIBS:=-lgtest -lgtest_main

RMF:=/bin/rm -f
RMFR:=/bin/rm -fr

##------------------------------------------------------------------------------
## 
## PROGRAM:=TestDriver
## 
## SOURCES:=TestDriver.cpp
## 
## OBJS:=TestDriver.o
## 
## INCLUDES:=prime
## 
## .PHONY: all
## all: TestDriver
## 
##------------------------------------------------------------------------------
## 
## $(PROGRAM).o: $(SOURCES) $(INCLUDES)
## $(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $(CXXDEBUG) -o $(PROGRAM).o $(PROGRAM).cpp
## 
## $(PROGRAM): $(PROGRAM).o
## $(CXX) $(LDFLAGS) -o $(PROGRAM) $(PROGRAM).o $(LOADLIBS)
## 
## clean:
## $(RMF) $(OBJS)
## 
## clean_all: clean
## $(RMF) $(PROGRAM)
## 
##------------------------------------------------------------------------------

.PHONY: all
all: sample1_unittest

## *** COMPILE THE MAIN CLASS, WHICH SHOULD STAND ALONE:
## *** MUST INLCUDE GTEST INCLUDE FILES ...
##
## /opt/local/bin/g++-mp-4.7 \
##    -c -Wall -Wextra -Wno-unused-parameter \
##    -I/opt/gtest/gtest-1.6.0/include \
##    -o sample1.o sample1.cc

sample1.o: prime_tables.h sample1.h sample1.cc
	/opt/local/bin/g++-mp-4.7 -c -Wall -Wextra -Wno-unused-parameter -I/opt/gtest/gtest-1.6.0/include -o sample1.o sample1.cc


## *** COMPILE THE *TEST* CLASS, WHICH BRINGS IN ALL GTEST STUFF:
## *** MUST INLCUDE GTEST INCLUDE FILES ...
##
## /opt/local/bin/g++-mp-4.7 \
##    -c -Wall -Wextra \
##    -I /opt/gtest/gtest-1.6.0/include \
##    -o sample1_unittest.o sample1_unittest.cc 

sample1_unittest.o: sample1_unittest.cc
	/opt/local/bin/g++-mp-4.7 -c -Wall -Wextra -I /opt/gtest/gtest-1.6.0/include -o sample1_unittest.o sample1_unittest.cc 


## *** LINK SAMPLE CODE WITH GTEST CODE:
##
## /opt/local/bin/g++-mp-4.7 \
##    -L/opt/gtest/gtest-1.6.0-static-debug \
##    sample1.o sample1_unittest.o -o sample1_unittest \
##    -lgtest -lgtest_main

sample1_unittest: sample1_unittest.o sample1.o
	/opt/local/bin/g++-mp-4.7 -L/opt/gtest/gtest-1.6.0-static-debug sample1.o sample1_unittest.o -o sample1_unittest -lgtest -lgtest_main


## *** TOTALLY WORKS ***
## ./sample1_unittest 


clean:
	$(RMF) sample1.o sample1_unittest.o

clean_all: clean
	$(RMF) sample1_unittest


##------------------------------------------------------------------------------
