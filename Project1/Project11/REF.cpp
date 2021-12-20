#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//用下列三段提升cin和cout的輸入和輸出效率
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
//https://www.twblogs.net/a/5c2f3157bd9eee35b21c6b09
class Solution {
public:
	int maxArea(vector<int>& height) {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		int i = 0, j = height.size() - 1;
		int maxarea = 0;
		// using two pointer

		while (i < j)
		{
			int l1 = height[i];
			int l2 = height[j];
			int breath = j - i;

			//taking minimum lengths
			int l = min(l1, l2);

			// max area calculating 
			maxarea = max(maxarea, l*breath);

			if (l1 < l2) i++;
			else j--;
		}

		return maxarea;
	}
};

