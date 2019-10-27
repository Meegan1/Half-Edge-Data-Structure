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

#include "Cartesian3.h"
#include "math.h"


// equality operator
bool Cartesian3::operator ==(const Cartesian3 &other)
	{ // Cartesian3::operator ==()
	return ((x == other.x) && (y == other.y) && (z == other.z));
	}

void Cartesian3::setValues(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}
// Cartesian3::operator ==()


// stream output
std::ostream & operator << (std::ostream &outStream, Cartesian3 value)
	{ // stream output
	outStream << value.x << " " << value.y << " " << value.z;
	return outStream;
	} // stream output

