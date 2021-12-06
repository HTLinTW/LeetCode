#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//�D�n�t�bunique���j�M�覡��KEY VALUE��
//�]�����O0�}�l�j�M
class Solution {
public:
	int unique(string &s, int front, int rear, char c) {
		for (int i = front; i < rear; ++i) {
			if (s[i] == c)
				return i;
		}
		return -1;
	}

	int lengthOfLongestSubstring(string s) {
		if (s.size() <= 1)
			return s.size();

		int res = 0;
		for (
			int front = 0, rear = 1;
			rear < s.size();
			++rear)
		{
			int t = unique(s, front, rear, s[rear]);
			if (t != -1)
				front = t + 1;

			res = max(res, rear - front + 1);
		}
		return res;

	}
};


//�ڪ��Q�k�O��쭫�ƮɦA�h����סA�̫ᵲ���ɦA��@��
//��L�覡�OŪ��C�Ӧr������@��
//���פu�㪺�ܷQ�k�W�ڪ��|�����
class SolutionPlus {
public:
	int unique(string &s, int front, int rear, char c) {
		for (int i = front; i < rear; ++i) {
			if (s[i] == c)
				return i;
		}
		return -1;
	}

	int lengthOfLongestSubstring(string s) {
		int front = 0, rear = 1;
		if (s.size() <= 1)
			return s.size();

		int res = 0;
		for (
			front = 0, rear = 1;
			rear < s.size();
			++rear)
		{
			int t = unique(s, front, rear, s[rear]);
			if (t != -1)
			{
				res = max(res, rear - front);
				front = t + 1;
			}

		}
		res = max(res, rear - 1 - front + 1);
		return res;

	}
};

//�޿�令�@�ˡA����MAP�t�׸�VECTOR�٬O���t
//��_KEY VALUE�A������mŪ�����
//�ΪŶ����t�סA���w��CHAR���W�u�Ȥ~���
class Solution2 {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int>freq(256, -1);			//�ŧi��l��1~256���O-1
		int l = 0, r = 0, ans = 0;
		while (r < s.length()) {
			if (freq[s[r]] != -1) {
				l = max(l, freq[s[r]] + 1);
			}
			freq[s[r]] = r;
			ans = max(ans, r - l + 1);
			r++;
		}
		return ans;

	}
};

int main()
{
	Solution2 s;

	string str = "ab";
	cout << endl;
	cout << endl << s.lengthOfLongestSubstring(str) << endl;
	cout << endl;
}