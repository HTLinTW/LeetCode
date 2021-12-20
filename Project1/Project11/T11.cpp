#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int ans = 0;

		for (int i = 0; i < height.size(); i++)
			for (int j = i + 1; j < height.size(); j++)
				ans = max((j - i)*min(height[i], height[j]), ans);

		return ans;
	}
};


class Solution2 {
public:
	int maxArea(vector<int>& height) {
		int ans = 0;

		for (int i = 0; i < height.size(); i++)
			for (int j = height.size() - 1; j > i; j--)
			{
				if (height[j] >= height[i])
				{
					ans = max((j - i)*min(height[i], height[j]), ans);
					break;
				}
				ans = max((j - i)*min(height[i], height[j]), ans);
			}
		return ans;
	}
};

class Solution3 {
public:
	int maxArea(vector<int>& height) {
		int ans = 0;

		for (int i = 0; i < height.size(); i++)
			for (int j = height.size() - 1; j > i; j--)
			{
				if (height[j] >= height[i])
				{
					ans = max((j - i)*min(height[i], height[j]), ans);
					break;
				}
			}

		for (int i = 0; i < height.size(); i++)
			for (int j = height.size() - 1; j > i; j--)
			{
				if (height[height.size() - j - 1] >= height[height.size() - i - 1])
				{
					ans = max((j - i)*min(height[height.size() - j - 1], height[height.size() - i - 1]), ans);
					break;
				}
			}

		return ans;
	}
};

class Solution4 {
public:
	int maxArea(vector<int>& height) {
		int ans = 0, l = 0, r = height.size() - 1,yMin = 0,tempMin = 0;

		while (l < r)
		{
			tempMin = min(height[r], height[l]);
			if (yMin < tempMin)
			{
				ans = max((r - l)*tempMin, ans);
				yMin = tempMin;
			}
			if (height[l] <= height[r])
				l++;
			else
				r--;
		}
		return ans;
	}
};

int main()
{
	Solution3 s1;
	vector<int> v = { 1,8,6,2,5,4,8,3,7 };

	cout << endl;
	cout << endl << s1.maxArea(v) << endl;
	cout << endl;
}