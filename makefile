CXX = g++
CXXFLAGS = -std=c++17 -I./include
PCH = include/pch.h
PCH_GCH = include/pch.h.gch
SOURCES = src/business_logic/car.cpp \
          src/business_logic/owner.cpp \
          src/main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = my_program

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

%.o: %.cpp $(PCH_GCH)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(PCH_GCH): $(PCH)
	$(CXX) -x c++-header $(PCH) -o $(PCH_GCH)

clean:
	rm -f $(OBJECTS) $(TARGET) $(PCH_GCH)

.PHONY: clean
