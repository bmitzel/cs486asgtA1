 * Programmer: Brian Mitzel
 * Email: bmitzel@csu.fullerton.edu
 * Course: CPSC 486
 * Assignment: A - Points, Planes, Rendering - Part 1
 * Due Date: 9/2/2014
 
points_planes.cpp is a C++ program that will calculate
whether a given point lies above, on, or below a given
plane.

Building:
Using the FreeBSD VM distributed by Professor Michael
Shafae, open a terminal window to the source directory and
enter the following command at the shell prompt:

gcc Plane.cpp Vec3.cpp Vec4.cpp VecMath.cpp
	points_planes.cpp -o points_planes -lstdc++

Executing:
From the same directory where you built the executable,
 1. Enter the command: ./points_planes

Features:
This program receives two files as input:

	1. random_points.txt: a set of 10,000 random points
	2. random_planes.txt: a set of 5 random planes

For each plane, two files are then output:

	1. planeXA.txt: a list of all the points above the plane
	2. planeXB.txt: a list of all the points below the plane

Where X is the number of the plane in order starting from
number 1.

Completed:
This program can calculate whether any random point is
above, on, or below any random plane, as required by the
assignment.

Bugs:
There are no known bugs at this time.
