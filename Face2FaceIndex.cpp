///////////////////////////////////////////////////
//
//
//  Created by Jake Meegan on 16/10/2019.
//
//	------------------------
//	Face2FaceIndex.cpp
//	------------------------
//
//	A class for converting .tri files into .face
//
///////////////////////////////////////////////////

#include <fstream>
#include "Face2FaceIndex.h"

bool Face2FaceIndex::ReadFileTriangleSoup(char *fileName) { // Face2FaceIndex::ReadFileTriangleSoup()
    // open the input file
    std::ifstream inFile(fileName);
    if (inFile.bad())
        return false;

    // set the number of vertices and faces
    unsigned long nTriangles = 0, nVertices = 0;
    // read in the number of vertices
    inFile >> nTriangles;
    nVertices = nTriangles * 3;

    // temp vertices
    std::vector<Cartesian3> tempVertices;
    // now allocate space for them all
    tempVertices.resize(nVertices);
    faces.resize(nTriangles);

    // counter for vertices vector size
    unsigned long verticesCount = 0;
    // now loop to read the vertices in
    unsigned long index;
    for (index = 0; inFile; index++)
    { // for each vertex
        if(index >= nVertices) // fail if index is higher than stated number of vertices
            return false;

        inFile >> tempVertices[index].x >> tempVertices[index].y >> tempVertices[index].z;

        // loop through currently stored vertices and check if exists
        bool alreadyExists = false;
        for (unsigned long i = 0; i < verticesCount; i++) {
            if ((vertices[i] == tempVertices[index])) { // if new vertices already exists, mark flag true
                alreadyExists = true;
                faces[index/3].setVertex(index%3, i); // save already stored ID for vertex
                break;
            }
        }
        // if already exists, continue to next vertex
        if(alreadyExists)
            continue;

        // if doesn't exist, store vertex and it's ID to faces
        vertices.emplace_back();
        vertices[verticesCount].setValues(tempVertices[index].x, tempVertices[index].y, tempVertices[index].z);
        verticesCount++;
        faces[index/3].setVertex(index%3, vertices.size()-1);
    } // for each vertex

    if(index < nVertices) // fail if iterated results is less than stated number of vertices
        return false;

    inFile.close();
    return true;
}

void Face2FaceIndex::printVertices(std::ostream &outStream) {
    unsigned long index = 0;
    for (auto & vertex : this->vertices) {
        outStream << "Vertex\t" << index << "\t" << vertex << std::endl;
        index++;
    }
}

void Face2FaceIndex::printFaces(std::ostream &outStream) {
    unsigned long index = 0;
    for (auto & face : this->faces) {
        outStream << "Face\t" << index << "\t" << face << std::endl;
        index++;
    }
}

void Face2FaceIndex::toFile(char *fName) {
    strcat(fName, ".face"); // add .face suffix to output filename
    std::ofstream outFile(fName, std::ofstream::out);

    // output commented header to file
    outFile << "# University of Leeds 2019-2020" << std::endl;
    outFile << "# COMP 5812M Assignment 2" << std::endl;
    outFile << "# Jake Meegan" << std::endl;
    outFile << "# 201036375" << std::endl;
    outFile << "#" << std::endl;
    outFile << "# Object Name: " << fName  << std::endl;
    outFile << "# Vertices=" << vertices.size() << " Faces=" << faces.size() << std::endl;
    outFile << "#" << std::endl;

    // output vertices and faces to file
    printVertices(outFile);
    printFaces(outFile);
    outFile.close(); //  close file
}
