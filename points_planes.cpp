/* 
 * Programmer: Brian Mitzel
 * Email: bmitzel@csu.fullerton.edu
 * Course: CPSC 486
 * Assignment: A - Points, Planes, Rendering
 * Due Date: 9/2/2014
 *
 * Filename: points_planes.cpp
 *
 * This program will calculate whether a given point lies
 * above, on, or below a given plane. It receives two files
 * as input:
 *
 * 	1. random_points.txt: a set of 10,000 random points
 *	2. random_planes.txt: a set of 5 random planes
 *
 * For each plane, two files are then output:
 *
 *	1. planeXA.txt: a list of all the points above the plane
 *	2. planeXB.txt: a list of all the points below the plane
 * 
 * Where X is the number of the plane in order starting from
 * number 1.
 *
 * This assignment is not graded.
 */

#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Plane.h"
#include "Vec3.h"
#include "VecMath.h"

#define FALSE 0
#define TRUE 1
#define DEBUG FALSE

const size_t NUM_POINTS = 10000;
const size_t NUM_PLANES = 5;
const float EPSILON = 0.0005f;

// The following to_string patch was posted by cMinor on 12/31/2013 at
// http://stackoverflow.com/questions/12975341/to-string-is-not-a-member-of-std-says-so-g
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

int main( int argc, char argv[] )
{
	std::ifstream fin;
	std::ofstream foutA;
	std::ofstream foutB;
	std::string filename;
	Vec3 points[ NUM_POINTS ];
	Plane planes[ NUM_PLANES ];

	fin.open( "random_points.txt", std::ifstream::in );
	for ( size_t i = 0; i < NUM_POINTS; i++ )
	{
		fin >> points[ i ].x;
		fin >> points[ i ].y;
		fin >> points[ i ].z;
#if DEBUG
		std::cout << "points[ " << i << " ].x = " << points[ i ].x << std::endl;
		std::cout << "points[ " << i << " ].y = " << points[ i ].y << std::endl;
		std::cout << "points[ " << i << " ].z = " << points[ i ].z << std::endl << std::endl;
#endif
	}
	fin.close();

	fin.open( "random_planes.txt", std::ifstream::in );
	for ( size_t i = 0; i < NUM_PLANES; i++ )
	{
		fin >> planes[ i ].normal.x;
		fin >> planes[ i ].normal.y;
		fin >> planes[ i ].normal.z;
		fin >> planes[ i ].offset;
#if DEBUG
		std::cout << "planes[ " << i << " ].normal.x = " << planes[ i ].normal.x << std::endl;
		std::cout << "planes[ " << i << " ].normal.y = " << planes[ i ].normal.y << std::endl;
		std::cout << "planes[ " << i << " ].normal.z = " << planes[ i ].normal.z << std::endl;
		std::cout << "planes[ " << i << " ].offset   = " << planes[ i ].offset << std::endl
			<< std::endl;
#endif
	}
	fin.close();

	for ( size_t i = 0; i < NUM_PLANES; i++ )
	{
		filename = "plane" + patch::to_string( i + 1 ) + "A.txt";
#if DEBUG
		std::cout << "foutA filename = " << filename << std::endl;
#endif
		foutA.open( filename.c_str(), std::ofstream::out );
		filename = "plane" + patch::to_string( i + 1 ) + "B.txt";
#if DEBUG
		std::cout << "foutB filename = " << filename << std::endl;
#endif
		foutB.open( filename.c_str(), std::ofstream::out );

		for ( size_t j = 0; j < NUM_POINTS; j++ )
		{
// 		determine if the point is above, on, or below the plane
			float result = planes[ i ].CheckPoint( points[ j ] );
			if ( std::abs( result ) > EPSILON )
			{
// 		if the point is above the plane:
				if ( result > 0.0f )
				{
// 			print the point to planeXA.txt
					foutA << points[ j ].x << ' ' << points[ j ].y << ' ' << points[ j ].z
						<< std::endl;
				}
// 		else if the point is below the plane:
				else
				{
// 			print the point to planeXB.txt
					foutB << points[ j ].x << ' ' << points[ j ].y << ' ' << points[ j ].z
						<< std::endl;
				}
			}
		}

		foutA.close();
		foutB.close();
	}
	
	return 0;
}
