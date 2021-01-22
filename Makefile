CXX=g++ 
CXXFLAGS=-std=c++14 -Wall -O -g -w -MMD -Werror=vla
SOURCES=$(wildcard *.cc)
OBJECTS=${SOURCES:.cc=.o}
DEPENDS=${OBJECTS:.o=.d}
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
EXEC=appexc

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC) $(LIBS)

%.o: %.cc 
	$(CXX) -c -o $@ $< $(CXXFLAGS)

-include ${DEPENDS} 

.PHONY: clean
clean:
	rm  -f $(OBJECTS) $(DEPENDS) $(EXEC)
