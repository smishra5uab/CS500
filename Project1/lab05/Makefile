INCLUDE = /opt/homebrew/Cellar/sfml/2.6.1/include
LIB = /opt/homebrew/Cellar/sfml/2.6.1/lib

SOURCES = main.cpp screenSaver.cpp 
OBJECTS = $(SOURCES:.cpp=.o)       
EXECUTABLE = screenSaver

all: $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	g++ -o $(EXECUTABLE) $(OBJECTS) -L$(LIB) -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cpp
	g++ -I$(INCLUDE) -c $<

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
