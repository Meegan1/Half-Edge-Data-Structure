///////////////////////////////////////////////////
//
//
//  Created by Jake Meegan on 16/10/2019.
//
//	------------------------
//	Face2FaceIndex.h
//	------------------------
//
//	A class for converting .tri files into .face
//
///////////////////////////////////////////////////

#ifndef FACE2FACEINDEX_FACE2FACEINDEX_H
#define FACE2FACEINDEX_FACE2FACEINDEX_H


#include <vector>
#include "Cartesian3.h"
#include "Face.h"

class Face2FaceIndex {
public:
    // vectors to store vertex and triangle information - relying on POD rule
    std::vector<Cartesian3> vertices;
    // vectors to store face
    std::vector<Face> faces;

    bool ReadFileTriangleSoup(char *fName);
    void printVertices(std::ostream &outStream);
    void printFaces(std::ostream &outStream);
    void toFile(char *fName);
};


#endif //FACE2FACEINDEX_FACE2FACEINDEX_H
