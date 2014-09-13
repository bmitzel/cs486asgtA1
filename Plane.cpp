/* 
 * Programmer: Brian Mitzel
 * Email: bmitzel@csu.fullerton.edu
 * Course: CPSC 486
 * 
 * Filename: Plane,cpp
 *
 * This C++ source file implements member functions for a 2D
 * plane..
 */

#include "Plane.h"

float Plane::CheckPoint( const Vec3& p )
{
	// Ax + By + Cz + D
	return ( normal.x * p.x ) + ( normal.y * p.y ) + ( normal.z * p.z ) + offset;
}
