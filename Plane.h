/* 
 * Programmer: Brian Mitzel
 * Email: bmitzel@csu.fullerton.edu
 * Course: CPSC 486
 * 
 * Filename: Plane,h
 *
 * This class represents a 2D plane using its normal and
 * its offset from the origin.
 */

#pragma once

#include "Vec3.h"

class Plane
{
public:
	Vec3 normal;
	float offset;
	
	// Default constructor
	// This plane defaults to y = 0.0
	Plane( float a = 0.0f, float b = 1.0f, float c = 0.0f, float d = 0.0f )
		: normal( a, b, c )
		, offset( d )
	{
	}
	
	// Destructor
	~Plane()
	{
	}
	
	float CheckPoint( const Vec3& p );
};
