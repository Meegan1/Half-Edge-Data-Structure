#ifndef FACE_H
#define FACE_H

#include <iostream>

// the class - we will rely on POD for sending to GPU
class Face
	{ // Face
	public:
	// the coordinates
    unsigned long v1, v2, v3;

	void setVertex(unsigned int vertex, unsigned long value);
	unsigned long & getVertex(unsigned int vertex);

	}; // Face

// stream output
std::ostream & operator << (std::ostream &outStream, Face value);
		
#endif