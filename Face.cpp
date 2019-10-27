#include "Face.h"

// constructors


void Face::setVertex(unsigned int vertex, unsigned long value) {
    switch(vertex) {
        case 0:
            this->v1 = value;
            break;
        case 1:
            this->v2 = value;
            break;
        case 2:
            this->v3 = value;
            break;
        default:
            throw std::out_of_range("Vertex index out of bounds");
    }
}

unsigned long & Face::getVertex(unsigned int vertex) {
    switch(vertex) {
        case 0:
            return this->v1;
        case 1:
            return this->v2;
        case 2:
            return this->v3;
        default:
            throw std::out_of_range("Vertex index out of bounds");
    }
}


// stream output
std::ostream & operator << (std::ostream &outStream, Face value)
	{ // stream output
	outStream << value.v1 << " " << value.v2 << " " << value.v3;
	return outStream;
	} // stream output
		
