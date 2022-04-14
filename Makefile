.PHONY: build

CXX := g++
CXXFLAGS := -Wall 
SFMLFLAGS := -lsfml-graphics -lsfml-window -lsfml-system
BUILDDIR := build
TARGET := Epicycloid
OBJ := src/main.o src/Program.o
INCLUDE := -I src

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $(BUILDDIR)/$(TARGET) $^ $(SFMLFLAGS)

%.o: %.cpp
	$(CXX) -c $(INCLUDE) -o $@ $^ $(CXXFLAGS)

run:
	./build/$(TARGET)
