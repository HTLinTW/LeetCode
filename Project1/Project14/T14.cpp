#include <iostream>
#include <vector>
#include<string>

using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ans = "";
		int i = 0;

		//��̵u������
		for (int j = 0; j < strs.size(); j++)
			if (strs[j].size() < strs[i].size())
				i = j;
		//�P�Y�}�l�U�Ӥ��
		for (int j = 0; j < strs[i].size(); j++)
		{
			int k = 0;
			for (; k < strs.size(); k++)
				if (strs[0][j] != strs[k][j])
					break;
			if (k == strs.size())
				ans += strs[0][j];
			else
				break;
		}
		return ans;
	}
};

int main()
{
	Solution s;
	vector<string> v = { "flower","flow","flight" };

	cout << endl;
	cout << endl << s.longestCommonPrefix(v) << endl;
	cout << endl;
}