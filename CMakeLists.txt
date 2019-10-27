cmake_minimum_required(VERSION 3.15)
project(face2faceindex)

set(CMAKE_CXX_STANDARD 14)

add_executable(face2faceindex FaceIndex.cpp Face2FaceIndex.cpp Face2FaceIndex.h Cartesian3.cpp Cartesian3.h Face.h Face.cpp)
add_executable(faceindex2directededge DirectedEdge.cpp FaceIndex2DirectedEdge.cpp FaceIndex2DirectedEdge.h Cartesian3.cpp Cartesian3.h Face.h Face.cpp)