#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//主要差在unique的搜尋方式比KEY VALUE快
//因為不是0開始搜尋
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


//我的想法是找到重複時再去算長度，最後結束時再算一次
//其他方式是讀到每個字元都算一次
//不論工具的話想法上我的會比較快
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

//邏輯改成一樣，但用MAP速度跟VECTOR還是有差
//比起KEY VALUE，直接位置讀取更快
//用空間換速度，有預期CHAR的上線值才能用
class Solution2 {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int>freq(256, -1);			//宣告初始值1~256都是-1
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