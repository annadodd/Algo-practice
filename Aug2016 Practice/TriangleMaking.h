//
//  TriangleMaking.h
//  Aug2016 Practice
//
//  Created by Anna Dodd on 9/4/16.
//  Copyright © 2016 Anna Dodd. All rights reserved.
//

#ifndef TriangleMaking_h
#define TriangleMaking_h
#include <math.h>
#include <algorithm>
#include <assert.h>


using namespace std;

/*
 Problem source: https://community.topcoder.com/stat?c=problem_statement&pm=14371
 
 Problem Statement
 * You have three sticks. Their current lengths are a, b, and c. You can shorten each of those sticks arbitrarily. Your goal is to produce three sticks with the following properties:
 * The length of each stick is a positive integer.
 * The three sticks can be used to build a triangle. The triangle must be non-degenerate. (I.e., it must have a positive area.)
 * The perimeter of the triangle must be as large as possible.
 * You are given the ints a, b, and c. Compute and return the largest possible perimeter of the triangle constructed from your three sticks.

 Definition
 Class:	TriangleMaking
 Method:	maxPerimeter
 Parameters:	int, int, int
 Returns:	int
 Method signature:	int maxPerimeter(int a, int b, int c)
 (be sure your method is public)


 Notes
 -	The return value is always defined. In other words, for any a, b, and c there is at least one way to build a valid triangle.
 */
class TriangleMaking
{
public:
	// Finds optimal perimeter for triangle with side lengths a, b, c
	// This may mean not shortening any sides
	int maxPerimeter(int a, int b, int c);
private:
	// Returns perimeter of triangle
	int perimeter(int a, int b, int c);
	// Uses triangle inequality to determine if valid triangle
	bool isTriangle(int a, int b, int c);
	// Used when side1, side2, and side3 do not form valid triangle
	// Finds optimal perimeter of by decrease hypotenus by as little as possible
	// until valid triangle
	int newPerimeter(int side1, int side2, int side3);
};


#endif /* TriangleMaking_h */
