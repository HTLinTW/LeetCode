#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		for (int i = nums.size() - 1; i >= 0; i--) {
			int val = nums[i];
			nums.pop_back();	//取出來後刪除
			int dif = target - val;

			std::vector<int>::iterator it;
			it = std::find(nums.begin(), nums.end(), dif);
			if (it != nums.end())			//nums.end()	指向vector最尾端元素的下一個位置
			{
				int j = it - nums.begin();	//nums.begin()	指向 vector 第一個元素
				vector<int> res = { j,i };
				return res;
			}
		}
		vector<int> res = { 0,0 };
		return res;
	}
};

//使用工具上，效能的差異
//https://shengyu7697.github.io/cpp-tutorial/
