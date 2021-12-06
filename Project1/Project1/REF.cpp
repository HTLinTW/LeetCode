#include <vector>
#include <unordered_map>
#include <iostream>

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
//https://jasonblog.github.io/note/c++/c++_stl_xue_xi_zong_7d5028_quan_976229.html


class Solution2 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> id;
		for (int i = 0; i < nums.size(); i++) {
			if (id[target - nums[i]] != 0) {
				return { id[target - nums[i]] - 1, i };
			}

			id[nums[i]] = i + 1;
		}

		return {};
	}

};

//看起來主要是用KEY,VALUE的特性
//讓讀值的速度更快
//並且不需要一個一個比較，而是直接看是否存在此值
//邏輯想法不同，是從過去找過的值來判斷


//int main()
//{
//	Solution t1;
//	vector<int> input;
//	input.resize(3);
//	input[0] = 1;
//	input[1] = -3;
//	input[2] = 10;
//
//	cout << endl;
//	cout << t1.twoSum(input, 7)[0] << endl;
//	cout << t1.twoSum(input, 7)[1] << endl;
//	cout << endl;
//}