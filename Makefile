# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# ****************************************************
# Targets needed to bring the executable up to date

main: 
	$(MAKE) face2faceindex
	$(MAKE) faceindex2directededge

face2faceindex: src/FaceIndex.o src/Face2FaceIndex.o src/Cartesian3.o src/Face.o
	$(CXX) $(CXXFLAGS) -o face2faceindex src/FaceIndex.o src/Face2FaceIndex.o src/Cartesian3.o src/Face.o

faceindex2directededge: src/DirectedEdge.o src/FaceIndex2DirectedEdge.o src/Cartesian3.o src/Face.o
	$(CXX) $(CXXFLAGS) -o faceindex2directededge src/DirectedEdge.o src/FaceIndex2DirectedEdge.o src/Cartesian3.o src/Face.o

# The main.o target can be written more simply