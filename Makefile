CXX=g++ 
CXXFLAGS=-std=c++14 -Wall -O -g -w -MMD -Werror=vla # use -MMD to generate dependencies
SOURCES=$(wildcard *.cc)   # list of all .cc files in the current directory
OBJECTS=${SOURCES:.cc=.o}  # .o files depend upon .cc files with same names
DEPENDS=${OBJECTS:.o=.d}   # .d file is list of dependencies for corresponding .cc file
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
EXEC=appexc

# First target in the makefile is the default target.
# Note that the LIBFLAGS must come last in the command
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC) $(LIBS)

%.o: %.cc 
	$(CXX) -c -o $@ $< $(CXXFLAGS)

-include ${DEPENDS} 

.PHONY: clean
clean:
	rm  -f $(OBJECTS) $(DEPENDS) $(EXEC)
