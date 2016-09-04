//
//  TriangleMaking.cpp
//  Aug2016 Practice
//
//  Created by Anna Dodd on 9/4/16.
//  Copyright © 2016 Anna Dodd. All rights reserved.
//

#include <stdio.h>
#include "TriangleMaking.h"

int TriangleMaking::maxPerimeter(int a, int b, int c)
{
	if (isTriangle(a, b, c))
	{
		return perimeter(a,b,c);
	}
	return newPerimeter(a, b, c);
}
int TriangleMaking::perimeter(int a, int b, int c)
{
	return a + b + c;
}
bool TriangleMaking::isTriangle(int a, int b, int c)
{
	// Triangle inequality thm
	return (a + b > c) && (a + c > b) && (b + c > a);
}
int TriangleMaking::newPerimeter(int side1, int side2, int side3)
{
	// Find which one has largest value
	int a = min(min(side1, side2), side3);
	int c = max(max(side1, side2), side3);
	int b = perimeter(side1, side2, side3) - a - c;

	// Value to subtract from c
	int x = 1;
	for (; x < c; ++x)
	{
		if (isTriangle(a, b, c - x))
		{
			break;
		}
	}
	return perimeter(a, b, c - x);
}