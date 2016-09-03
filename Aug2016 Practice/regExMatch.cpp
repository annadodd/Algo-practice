//
//  RegExMatch.h
//  Aug2016 Practice
//
//  Created by Anna Dodd on 9/1/16.
//  Copyright © 2016 Anna Dodd. All rights reserved.
//

#include <string>
#include <iostream>

using namespace std;

bool isSubstring(const string& original, const string& sub)
{
	int startIdx = 0;
	while ((startIdx + sub.length() - 1) < original.length())
	{
		int origIdx = startIdx;
		int i = 0;
		for (;(i < sub.length()) && (original[origIdx] == sub[i]);
			 ++i, ++origIdx)
		{
		}
		if (i == sub.length())
		{
			return true;
		}
		++startIdx;
	}
	return false;
}

/*

 Given a pattern string and a test string, Your task is to implement RegEx
 substring matching. If the pattern is preceded by a ^, the pattern(excluding
 the ^) will be matched with the starting position of the text string.
 Similarly, if it is preceded by a $, the pattern(excluding the ^) will be
 matched with the ending position of the text string. If no such markers are
 present, it will be checked whether pattern is a substring of test.

 The first line of input contains an integer T denoting the no of test cases .
 Then T test cases follow. Each test case contains two lines. The first line
 of each test case contains a pattern string. The second line of each test case
 consists of a text string.
 
 http://www.practice.geeksforgeeks.org/problem-page.php?pid=1313

 */

bool regExMatch(const string& pattern, const string& text)
{
	int patternLength = pattern.length() - 1;
	int patternStart;
	int patternEnd;
	if (patternLength > text.length())
	{
		return false;
	}

	int startIdx;
	if (pattern[0] == '^')
	{
		startIdx = 0;
		patternStart = 1;
		patternEnd = patternLength;
	}
	else if (pattern[pattern.length() - 1] == '$')
	{
		startIdx = text.length() - patternLength;
		patternStart = 0;
		patternEnd = patternLength - 1;
	}
	else
	{
		return isSubstring(text, pattern);
	}
	// Start at second character in pattern to skip over symbol '^' or '$'
	for (int i = patternStart; i <= patternEnd; ++i)
	{
		if (text[startIdx] != pattern[i])
		{
			return false;
		}
		++startIdx;
	}
	return true;
}

int main()
{
	int numTests;
	string dummy;
	cin >> numTests;
	getline(cin, dummy);
	for (int i = 0; i < numTests; ++i)
	{
		string pattern;
		string text;
		cin >> pattern;
		getline(cin, dummy);
		cin >> text;
		cout << regExMatch(pattern, text) << "\n";
	}
	return 0;
}
