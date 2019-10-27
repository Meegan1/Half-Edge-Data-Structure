//
// Created by Jake Meegan on 16/10/2019.
//

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

    // now loop to read the vertices in, and hope nothing goes wrong
    for (unsigned long index = 0; index < nVertices; index++)
    { // for each vertex
        inFile >> tempVertices[index].x >> tempVertices[index].y >> tempVertices[index].z;

        // loop through currently stored vertices and check if exists
        bool alreadyExists = false;
        for (unsigned long i = 0; i < vertices.size(); i++) {
            if (!(vertices[i] == tempVertices[index]))
                continue;

            alreadyExists = true;
            faces[index/3].setVertex(index%3, i);
            break;
        }
        // if doesn't exist, store vertex and index to faces
        if(!alreadyExists) {
            vertices.emplace_back();
            vertices.back().setValues(tempVertices[index].x, tempVertices[index].y, tempVertices[index].z);

            faces[index/3].setVertex(index%3, vertices.size()-1);
        }
    } // for each vertex

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

    outFile << "# University of Leeds 2019-2020" << std::endl;
    outFile << "# COMP 5812M Assignment 2" << std::endl;
    outFile << "# Jake Meegan" << std::endl;
    outFile << "# 201036375" << std::endl;
    outFile << "#" << std::endl;
    outFile << "# Object Name: " << fName  << std::endl;
    outFile << "# Vertices=" << vertices.size() << " Faces=" << faces.size() << std::endl;
    outFile << "#" << std::endl;

    printVertices(outFile);
    printFaces(outFile);
    outFile.close();
}
