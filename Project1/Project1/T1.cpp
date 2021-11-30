#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		//vector<int> ans;
		int temp;

		//if (nums.size() < 2 && nums.size() > 10000)
		//	return ans;

		//for (int i = 0; i < nums.size(); i++)
		//{
		//	if (nums[i] < -pow(10, 9) && nums[i] > pow(10, 9))
		//		return ans;
		//}

		//if (target < -pow(10, 9) && target > pow(10, 9))
		//	return ans;

		for (int i = 0; i < nums.size(); i++)
		{
			temp = target - nums[i];
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (temp == nums[j])
				{
					//ans.resize(2);
					//ans[0] = i;
					//ans[1] = j;
					return {i,j};
				}
			}
		}

		//return ans;
		return {};
	}
};


class Solution2 {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		set<int> myset;
		int temp;

		for (int i = 0; i < nums.size(); i++)
		{
			temp = target - nums[i];
			myset.insert(nums[i]);
			if (myset.count(temp) == 1)
			{
				for (int j = 0; j < i; j++)
				{
					if (temp == nums[j])
					{
						return { i,j };
					}
				}
			}
		}
		return {};
	}
};



int main()
{
	Solution t1;
	vector<int> input;
	input.resize(10);
	input[0] = 1;
	input[1] = -3;
	input[2] = 2;
	input[3] = 15;
	input[4] = 11;
	input[5] = 7;
	input[6] = -5;
	input[7] = 100;
	input[8] = 100;
	input[9] = 10;

	cout << endl;
	cout << t1.twoSum(input, 7)[0] << endl;
	cout << t1.twoSum(input, 7)[1] << endl;
	cout << endl;
}

