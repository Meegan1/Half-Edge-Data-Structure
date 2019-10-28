# University of Leeds 2019-2020
# COMP 5812M Assignment 2
Student Name: Jake Meegan
Student ID: 201036375

# Algorithmic Complexity #
The worst case complexity for each of the programs is O(n^2).

# Usage #
make
./face2faceindex [input file] [output name]
./faceindex2directededge [input file] [output name]

# Example Usage #
To generate a tetrahedron.face file from .tri
./face2faceindex ../models/tetrahedron.tri tetrahedron

To generate a tetrahedron.diredge file from .face
./face2faceindex ../models/tetrahedron.face tetrahedron