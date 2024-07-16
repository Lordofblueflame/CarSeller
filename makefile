CXX = g++
CXXFLAGS = -std=c++17 -I./include
PCH = include/pch.h
PCH_GCH = include/pch.h.gch
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = my_program.exe

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp $(PCH_GCH)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PCH_GCH): $(PCH)
	$(CXX) -x c++-header $(PCH) -o $(PCH_GCH)

clean:
ifeq ($(OS),Windows_NT)
	del /F /Q $(subst /,\,$(OBJECTS)) $(subst /,\,$(TARGET)) $(subst /,\,$(PCH_GCH))
else
	rm -f $(OBJECTS) $(TARGET) $(PCH_GCH)
endif

.PHONY: clean
