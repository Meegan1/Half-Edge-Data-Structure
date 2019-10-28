///////////////////////////////////////////////////
//
//
//  Created by Jake Meegan on 16/10/2019.
//
//	------------------------
//	DirectedEdge.cpp
//	------------------------
//
//  Entrypoint for .face -> .diredge program
//
///////////////////////////////////////////////////
#include <iostream>
#include "FaceIndex2DirectedEdge.h"

int main(int argc, char **argv)
{
    FaceIndex2DirectedEdge surface;
    // check the args to make sure there's an input file
    if (argc == 3)
    { // two parameters - read a file
        if (!surface.ReadFileFaceIndex(argv[1]))
        {
            printf("Read failed for file %s\n", argv[1]);
            exit(0);
        }
        else
        {
            surface.toFile(argv[2]);
        }
    } // two parameters - read a file
    else
    { // too many parameters
        printf("Usage: %s filename output\n", argv[0]);
        exit (0);
    } // too many parameters

    // paranoid return value
    exit(0);
} // main()