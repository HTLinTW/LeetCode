#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		for (int i = nums.size() - 1; i >= 0; i--) {
			int val = nums[i];
			nums.pop_back();	//���X�ӫ�R��
			int dif = target - val;

			std::vector<int>::iterator it;
			it = std::find(nums.begin(), nums.end(), dif);
			if (it != nums.end())			//nums.end()	���Vvector�̧��ݤ������U�@�Ӧ�m
			{
				int j = it - nums.begin();	//nums.begin()	���V vector �Ĥ@�Ӥ���
				vector<int> res = { j,i };
				return res;
			}
		}
		vector<int> res = { 0,0 };
		return res;
	}
};

//�ϥΤu��W�A�į઺�t��
//https://shengyu7697.github.io/cpp-tutorial/
