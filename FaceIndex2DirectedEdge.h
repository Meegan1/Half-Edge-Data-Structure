///////////////////////////////////////////////////
//
//
//  Created by Jake Meegan on 16/10/2019.
//
//	------------------------
//	FaceIndex2DirectedEdge.h
//	------------------------
//
//	A class for converting .face files into .diredge
//
///////////////////////////////////////////////////

#ifndef FACEINDEX2DIRECTEDEDGE_FACEINDEX2DIRECTEDEDGE_H
#define FACEINDEX2DIRECTEDEDGE_FACEINDEX2DIRECTEDEDGE_H


#include <vector>
#include "Cartesian3.h"
#include "Face.h"

class FaceIndex2DirectedEdge {
private:
    // vectors to store vertex and triangle information - relying on POD rule
    std::vector<Cartesian3> vertices;
    // vectors to store face
    std::vector<Face> faces;

    std::vector<unsigned long> firstDirectedEdge;
    std::vector<long> otherHalf;
    std::vector<unsigned long> nonManifoldEdges;

public:
    bool ReadFileFaceIndex(char *fName);
    long getGenus();
    void printVertices(std::ostream &outStream);
    void printFirstDirectedEdge(std::ostream &outStream);
    void printFaces(std::ostream &outStream);
    void printOtherHalf(std::ostream &outStream);
    void printNonManifold(std::ostream &outStream);

    void toFile(char *fName);

    FaceIndex2DirectedEdge();
};


#endif //FACEINDEX2DIRECTEDEDGE_FACEINDEX2DIRECTEDEDGE_H
