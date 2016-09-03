//
//  wordBreak.h
//  Aug2016 Practice
//
//  Created by Anna Dodd on 9/2/16.
//  Copyright © 2016 Anna Dodd. All rights reserved.
//

#ifndef wordBreak_h
#define wordBreak_h

#include <string>
#include <set>

set<string> dict;

/*
 
 Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.

 Consider the following dictionary
 { i, like, sam, sung, samsung, mobile, ice,
 cream, icecream, man, go, mango}

 Input:  ilike
 Output: Yes
 The string can be segmented as "i like".

 Input:  ilikesamsung
 Output: Yes
 The string can be segmented as "i like samsung" or "i like sam sung".

 Input:
 First line is integer T denoting number of test cases. 1<=T<=100.
 Every test case has 3 lines.
 First line is N number of words in dictionary. 1<=N<=12.
 Second line contains N strings denoting the words of dictionary. Length of each word is less than 15.
 Third line contains a string S of length less than 1000.

 Output:
 Print 1 is possible to break words, else print 0.
 
 http://www.practice.geeksforgeeks.org/problem-page.php?pid=1277

 */

bool inDict(const string& str)
{
	return dict.find(str) != dict.end();
}

bool wordBreak(const string& str)
{
	// Bottom up approach
	// Computes whether you can break the first part of the
	// word to determine if you can break the entire word

	// Assumes dict is filled in with values before using/testing

	bool canBreak[str.length() + 1];
	canBreak[0] = true;
	for (int i = 1; i <= str.length(); ++i)
	{
		bool canBreakI = inDict(str.substr(0,i));
		for (int j = i - 1; j > 0; --j)
		{
			if (canBreakI)
			{
				break;
			}
			canBreakI = canBreak[j] && inDict(str.substr(j,i - j));
		}
		canBreak[i] = canBreakI;
	}
	return canBreak[str.length()];
}

#endif /* wordBreak_h */
