//
// Created by Jake Meegan on 16/10/2019.
//

#include <fstream>
#include "FaceIndex2DirectedEdge.h"


FaceIndex2DirectedEdge::FaceIndex2DirectedEdge() {
    vertices.resize(0);
    firstDirectedEdge.resize(0);
    faces.resize(0);
    otherHalf.resize(0);
}

bool FaceIndex2DirectedEdge::ReadFileFaceIndex(char *fileName) { // FaceIndex2DirectedEdge::ReadFileTriangleSoup()
    // open the input file
    std::ifstream inFile(fileName);
    if (inFile.bad())
        return false;

    inFile.seekg (0, inFile.end);
    int length = inFile.tellg();
    inFile.seekg (0, inFile.beg);


    while(inFile) {
        std::string string;
        inFile >> string;
        if(string[0] == '#') {
            inFile.ignore(length, '\n');
            continue;
        }
        else if(string == "Vertex") {
            long index;
            inFile >> index;

            if(index >= vertices.size())
                vertices.resize(index+1);

            inFile >> vertices[index].x >> vertices[index].y >> vertices[index].z;
        }
        else if(string == "Face") {
            long index;
            inFile >> index;

            if(index >= faces.size())
                faces.resize(index+1);

            inFile >> faces[index].v1 >> faces[index].v2 >> faces[index].v3;
        }
    }
    inFile.close();

    unsigned long totalHalfEdges = faces.size()*3;

    firstDirectedEdge.resize(vertices.size());
    for(unsigned long i = 0; i < firstDirectedEdge.size(); i++) {
        for(unsigned long j = 0; j < totalHalfEdges; j++) {
            if(faces[j/3].getVertex(j%3) != i)
                continue;

            firstDirectedEdge[i] = j;
            break;
        }
    }

    otherHalf.resize(totalHalfEdges, -1); // resize vector and set default to -1

    for(unsigned long i = 0; i < totalHalfEdges; i++) {
        if(otherHalf[i] != -1)
            continue;

        unsigned long firstVertex = faces[i/3].getVertex(i%3);
        unsigned long secondVertex = faces[i/3].getVertex((i+1)%3);

        for(unsigned long j = i+1; j < totalHalfEdges; j++) {
            if(otherHalf[j] != -1)
                continue;

            if(firstVertex == faces[j/3].getVertex((j+1)%3) && secondVertex == faces[j/3].getVertex(j%3)) {
                otherHalf[i] = j;
                otherHalf[j] = i;
            }
        }

        if(otherHalf[i] == -1)
            nonManifoldEdges.emplace_back(i);
    }

    return true;
}

void FaceIndex2DirectedEdge::printVertices(std::ostream &outStream) {
    unsigned long index = 0;
    for (auto & vertex : this->vertices) {
        outStream << "Vertex\t" << index << "\t" << vertex << std::endl;
        index++;
    }
}

void FaceIndex2DirectedEdge::printFirstDirectedEdge(std::ostream &outStream) {
    unsigned long index = 0;
    for (auto & edge : this->firstDirectedEdge) {
        outStream << "FirstDirectedEdge\t" << index << "\t" << edge << std::endl;
        index++;
    }
}

void FaceIndex2DirectedEdge::printFaces(std::ostream &outStream) {
    unsigned long index = 0;
    for (auto & face : this->faces) {
        outStream << "Face\t" << index << "\t" << face << std::endl;
        index++;
    }
}

void FaceIndex2DirectedEdge::printOtherHalf(std::ostream &outStream) {
    unsigned long index = 0;
    for (auto & edge : this->otherHalf) {
        outStream << "OtherHalf\t" << index << "\t" << edge << std::endl;
        index++;
    }
}

void FaceIndex2DirectedEdge::printNonManifold(std::ostream &outStream) {
    for (auto & edge : this->nonManifoldEdges) {
        outStream << "Non-Manifold Found At Edge: " << edge
        << "\tVertex: " << faces[edge/3].getVertex(edge%3)
        << "\t("
        << vertices[faces[edge/3].getVertex(edge%3)].x << ", "
        << vertices[faces[edge/3].getVertex(edge%3)].y << ", "
        << vertices[faces[edge/3].getVertex(edge%3)].z
        << ")"
        << std::endl;
    }
}

void FaceIndex2DirectedEdge::toFile(char *fName) {
    if(nonManifoldEdges.size() > 0) {
        std::cout << "ERROR: " <<  fName << " is not manifold!" << std::endl;
        printNonManifold(std::cout);
        return;
    }

    strcat(fName, ".diredge");
    std::ofstream outFile(fName, std::ofstream::out);

    outFile << "# University of Leeds 2019-2020" << std::endl;
    outFile << "# COMP 5812M Assignment 2" << std::endl;
    outFile << "# Jake Meegan" << std::endl;
    outFile << "# 201036375" << std::endl;
    outFile << "#" << std::endl;
    outFile << "# Object Name: " << fName << std::endl;
    outFile << "# Vertices=" << vertices.size() << " Faces=" << faces.size() << std::endl;
    outFile << "#" << std::endl;

    printVertices(outFile);
    printFirstDirectedEdge(outFile);
    printFaces(outFile);
    printOtherHalf(outFile);
    outFile.close();

    std::cout << fName << " has been generated" << std::endl;
    std::cout << "Genus: " << getGenus() << std::endl;
}

long FaceIndex2DirectedEdge::getGenus() {
    long v = this->vertices.size();
    long e = 3*this->faces.size()/2;
    long f = this->faces.size();
    return -(v - e + f - 2)/2;
}