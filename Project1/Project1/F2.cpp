#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
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

//�ݰ_�ӥD�n�O��KEY,VALUE���S��
//��Ū�Ȫ��t�ק��
//�åB���ݭn�@�Ӥ@�Ӥ���A�ӬO�����ݬO�_�s�b����
//�޿�Q�k���P�A�O�q�L�h��L���ȨӧP�_

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