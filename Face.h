///////////////////////////////////////////////////
//
//
//  Created by Jake Meegan on 16/10/2019.
//
//	------------------------
//	Face.h
//	------------------------
//
//	A minimal class for storing a face with its associated vertex ID's
//
///////////////////////////////////////////////////

#ifndef FACE_H
#define FACE_H

#include <iostream>

// the class - we will rely on POD for sending to GPU
class Face
	{ // Face
	public:
	// the coordinates
    unsigned long v1, v2, v3;

    // Get/Set vertex via ID (0 -> v1, 1 -> v2, 2 -> v3)
	void setVertex(unsigned long vertex, unsigned long value);
	unsigned long & getVertex(unsigned long vertex);

	}; // Face

// stream output
std::ostream & operator << (std::ostream &outStream, Face value);
		
#endif