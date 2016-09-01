//
//  RodCut.h
//  Aug2016 Practice
//
//  Created by Anna Dodd on 8/30/16.
//  Copyright © 2016 Anna Dodd. All rights reserved.
//

#ifndef RodCut_h
#define RodCut_h

#include <algorithm>

using namespace std;

/**
 *  maxRodRevenue
 *
 *  @param prices price[i] gives price of rod length i; assumed to be size n+1
 *  @param n      Length of rod to cut
 *
 *  @return Returns max revenue that can be made with the rod by optimally
 *	cutting it
 *	
 *	Bottom up dynamic approach; O(n) time complexity; O(n) space complexity
 */
int maxRodRevenue(int prices[], int n)
{
	int maxRodValue[n + 1];
	maxRodValue[0] = 0;
	maxRodValue[1] = prices[1];
	for (int ii = 2; ii <= n; ++ii)
	{
		int maxValue = prices[ii];
		for (int jj = 1; jj < ii; ++jj)
		{
			maxValue = max(maxValue, prices[jj] + maxRodValue[ii - jj]);
		}
		maxRodValue[ii] = maxValue;
	}
	return maxRodValue[n];
}

#endif /* RodCut_h */
