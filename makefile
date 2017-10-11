CXX = g++
INCLUDES= -I./
CXXFLAGS = -g $(INCLUDES) -std=c++0x
TEST_LINKFLAGS= -lcppunit

MAINTEST = mainTest
MAINRUN = mainRun

TEST_SOURCES = $(wildcard *.cpp $(foreach dir,$(MAINTEST),$(wildcard $(dir)/*.cpp)))
TEST_HEADERS = $(wildcard *.h $(foreach dir,$(MAINTEST),$(wildcard $(dir)/*.h)))
TEST_OBJECTS = $(TEST_SOURCES:%.cpp=%.o)

RUN_SOURCES = $(wildcard *.cpp $(foreach dir,$(MAINRUN),$(wildcard $(dir)/*.cpp)))
RUN_HEADERS = $(wildcard *.h $(foreach dir,$(MAINRUN),$(wildcard $(dir)/*.h)))
RUN_OBJECTS = $(RUN_SOURCES:%.cpp=%.o)

default: runTests

%.o: %.cpp
	@echo "Compiling $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@ 

runTests: $(TEST_OBJECTS)
	@echo "Building $@"
	@$(CXX) $(CXXFLAGS) $(TEST_OBJECTS) $(TEST_LINKFLAGS) -o $@
	@echo ""
	@echo "Everything worked :-) "
	@echo ""

run: $(RUN_OBJECTS)
	@echo "Building $@"
	@$(CXX) $(CXXFLAGS) $(RUN_OBJECTS) -o $@
	@echo ""
	@echo "Everything worked :-) "
	@echo ""

clean:
	-@rm -f runTests
	-@rm -f run
	-@rm -f *.o 
	-@rm -f mainTest/*.o 
	-@rm -f mainRun/*.o 
