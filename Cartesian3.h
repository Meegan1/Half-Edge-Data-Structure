///////////////////////////////////////////////////
//
//	Hamish Carr
//	January, 2018
//
//	------------------------
//	Cartesian3.h
//	------------------------
//	
//	A minimal class for a point in Cartesian space
//	
///////////////////////////////////////////////////

#ifndef CARTESIAN3_H
#define CARTESIAN3_H

#include <iostream>

// the class - we will rely on POD for sending to GPU
class Cartesian3
	{ // Cartesian3
	public:
	// the coordinates
	float x, y, z;

	void setValues(float x, float y, float z);

	// equality operator
	bool operator ==(const Cartesian3 &other);

	}; // Cartesian3

// stream output
std::ostream & operator << (std::ostream &outStream, Cartesian3 value);
		
#endif