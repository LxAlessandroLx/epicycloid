.PHONY: build

SHELL := /bin/bash
CXX := g++
CXXFLAGS := -Wall -lsfml-graphics -lsfml-window -lsfml-system
BUILDDIR := build
TARGET := main
SRC := src/main.cpp src/Program.cpp
INCLUDE := -I src

build:
	$(CXX) -o $(BUILDDIR)/$(TARGET) $(INCLUDE) $(SRC) $(CXXFLAGS)

time:
	time $(CXX) -o $(BUILDDIR)/$(TARGET) $(INCLUDE) $(SRC) $(CXXFLAGS)

run:
	./build/main
