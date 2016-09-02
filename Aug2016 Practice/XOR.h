//
//  XOR.h
//  Aug2016 Practice
//
//  Created by Anna Dodd on 9/1/16.
//  Copyright © 2016 Anna Dodd. All rights reserved.
//

#ifndef XOR_h
#define XOR_h

#include <iostream>
#include <vector>
using namespace std;

/*
 
 The first line of input takes the number of test cases, T.
 Then T test cases follow.Each test case consists of 2 lines.
 The first line of each test case takes the number of inputs
 to the XOR Gate, N. The second line of each test case takes
 N space separated integers denoting the inputs to the  XOR Gate.
 Note that the inputs can be either 1's or 0's.
 
 http://www.practice.geeksforgeeks.org/problem-page.php?pid=1353
 
 */

void NXOR()
{
	int numTests;
	cin >> numTests;
	for (int i = 0; i < numTests; ++i)
	{
		int N;
		cin >> N;
		int input;
		cin >> input;
		for (int j = 1; j < N; ++j)
		{
			int value;
			cin >> value;
			input = ~(input & value) & (input | value);
		}
		cout << input << endl;
	}
}


#endif /* XOR_h */
