//
//  paintFence.h
//  Aug2016 Practice
//
//  Created by Anna Dodd on 9/2/16.
//  Copyright © 2016 Anna Dodd. All rights reserved.
//

#ifndef paintFence_h
#define paintFence_h

// Returns number of ways to paint a fence of n posts with k colors
// such that no more than two posts in a row are painted the same color

int paintFence(int n, int k)
{
	// total ways to paint posts = # ways with last 2 colors same
	//				+ # ways with last 2 colors differing

	// save two arrays:
	int same[n+1]; // same[i] = # ways with last 2 colors same for i posts
	int diff[n+1]; // diff[i] = # ways with last 2 colors diff for i posts

	// Start by computing for i = 1 ... n
	for (int i = 1; i <= n; ++i)
	{
		// Case: last two fence posts same, we must paint
		// next post a new color
		diff[i] = same[i - 1] * (k - 1);

		// Case: previous fence post is color x (different
		// from the fence post before it) and we paint the next
		// post a different color
		diff[i] += diff[i - 1] * (k - 1);

		// Case: previous fence post is color x (different
		// from the fence post before it) and we paint the next
		// post color x
		same[i] = diff[i - 1];
	}
	return same[n] + diff[n];
}

#endif /* paintFence_h */
