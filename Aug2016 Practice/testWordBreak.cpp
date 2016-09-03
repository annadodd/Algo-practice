//
//  testXOR.cpp
//  Aug2016 Practice
//
//  Created by Anna Dodd on 9/1/16.
//  Copyright © 2016 Anna Dodd. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <set>
#include <string>
#include "XOR.h"
#include "wordBreak.h"

using namespace std;

int main()
{
	/*
	 Test case from http://www.geeksforgeeks.org/dynamic-programming-set-32-word-break-problem/
	 */

	dict.insert("i");
	dict.insert("like");
	dict.insert("sam");
	dict.insert("sung");
	dict.insert("samsung");
	dict.insert("mobile");
	dict.insert("ice");
	dict.insert("cream");
	dict.insert("icecream");
	dict.insert("and");
	dict.insert("man");
	dict.insert("go");
	dict.insert("mango");

	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
	wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
	wordBreak("")? cout <<"Yes\n": cout << "No\n";
	wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";

	return 0;
}
