#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int i = 0, j = 0;
		if (s == p)
			return true;
		else if (p == ".*")
			return true;
		else if (p == "")
			return false;

		for (i = 0; i < p.length() - 1; i++)
		{
			if (p[i + 1] == '*')
			{
				if (p[i] == '.')
				{
					if (isMatch(s.substr(j), p.substr(i + 2)))
						return true;
					for (; j < s.length(); j++)
					{
						if (isMatch(s.substr(j + 1), p.substr(i + 2)))
							return true;
					}
					if (j == s.length() && i == p.length() - 2)
						return true;
					return false;
				}
				else
				{
					if (isMatch(s.substr(j), p.substr(i + 2)))
						return true;
					for (; s[j] == p[i]; j++)
					{
						if (isMatch(s.substr(j + 1), p.substr(i + 2)))
							return true;
					}
					if (j == s.length() && i == p.length() - 2)
						return true;
					return false;
				}
			}

			if (j >= s.length())
				return false;

			if (s[j] == p[i] || p[i] == '.')
			{
				j++;
			}
			else
				return false;

		}

		if ((s[j] == p[i] || p[i] == '.') && j == s.length() - 1)
			return true;
		return false;

	}
};

//全部遞迴函數
class Solution2 {
public:
	bool isMatch(string s, string p) {
		if (s == p)
			return true;
		else if (p == ".*")
			return true;
		else if (p == "")
			return false;

		if (p[1] == '*')
		{
			if (isMatch(s, p.substr(2)))
				return true;
			else if ((s[0] == p[0] || p[0] == '.') && s.length() > 0)
				return isMatch(s.substr(1), p);
			return false;
		}

		if ((s[0] == p[0] || p[0] == '.') && s.length() > 0)
			return isMatch(s.substr(1), p.substr(1));
		return false;
	}
};

//Fibonacci加速
class Solution3 {
public:
	//s與p有範圍限制
	//不然需要用到動態陣列
	//因為遞迴所以要放在函數外
	int f[21][31];

	bool isMatch(string s, string p) {
		if (f[0][0] != 1)
		{
			for (int i = 0; i < 21; i++)
				for (int j = 0; j < 31; j++)
					f[i][j] = -1;
			f[0][0] = 1;
		}

		if (f[s.length()][p.length()] != -1)
			return f[s.length()][p.length()];

		if (s == p)
			return f[s.length()][p.length()] = 1;
		else if (p == ".*")
			return f[s.length()][p.length()] = 1;
		else if (p == "")
			return f[s.length()][p.length()] = 0;

		if (p[1] == '*')
		{
			if (isMatch(s, p.substr(2)))
				return f[s.length()][p.length()] = 1;
			else if ((s[0] == p[0] || p[0] == '.') && s.length() > 0)
				return  f[s.length()][p.length()] = isMatch(s.substr(1), p);
			return f[s.length()][p.length()] = 0;
		}

		if ((s[0] == p[0] || p[0] == '.') && s.length() > 0)
			return  f[s.length()][p.length()] = isMatch(s.substr(1), p.substr(1));
		return f[s.length()][p.length()] = 0;
	}
};


//Fibonacci直接矩陣算出來後
//丟位置直接給答案
//因為全部都算所以理論上會比Solution3的加速慢
class Solution4 {
public:

	bool isMatch(string s, string p) {
		//一開始INIT就打算全算出來
		//不用遞迴所以可以直接放裡面
		//除非會重複用再改到外面
		int f[21][31];
		for (int i = 0; i <= s.length(); i++)
		{
			for (int j = 0; j <= p.length(); j++)
			{
				if (s.substr(s.length() - i) == p.substr(p.length() - j))
				{
					f[i][j] = 1;
					continue;
				}
				else if (p.substr(p.length() - j) == ".*")
				{
					f[i][j] = 1;
					continue;
				}
				else if (j == 0)
				{
					f[i][j] = 0;
					continue;
				}
				else if (p[p.length() - j] == '*')
				{
					f[i][j] = 0;
					continue;
				}

				if (p[p.length() + 1 - j] == '*')
				{
					if (f[i][j - 2])
					{
						f[i][j] = 1;
						continue;
					}
					else if (i > 0)
					{
						if ((s[s.length() - i] == p[p.length() - j] || p[p.length() - j] == '.') && i > 0)
						{
							f[i][j] = f[i - 1][j];
							continue;
						}
					}
					f[i][j] = 0;
					continue;
				}
				if (i > 0)
				{
					if ((s[s.length() - i] == p[p.length() - j] || p[p.length() - j] == '.'))
					{
						f[i][j] = f[i - 1][j - 1];
						continue;
					}
				}
				f[i][j] = 0;
			}
		}

		return f[s.length()][p.length()];
	}
};



//原本寫的邏輯用Fibonacci加速的話
//只要有遞迴就可以用Fibonacci加速
//所以遞迴的話不要寫得太複雜
//寫簡單一點然後用Fibonacci加速會更好理解
class Solution5 {
public:
	int f[21][31];
	bool isMatch(string s, string p) {
		if (f[0][0] != 1)
		{
			for (int a = 0; a < 21; a++)
				for (int b = 0; b < 31; b++)
					f[a][b] = -1;
			f[0][0] = 1;
		}

		if (f[s.length()][p.length()] != -1)
			return f[s.length()][p.length()];

		int i = 0, j = 0;
		if (s == p)
			return f[s.length()][p.length()] = 1;
		else if (p == ".*")
			return f[s.length()][p.length()] = 1;
		else if (p == "")
			return f[s.length()][p.length()] = 0;

		for (i = 0; i < p.length() - 1; i++)
		{
			if (p[i + 1] == '*')
			{
				if (p[i] == '.')
				{
					if (f[s.length()][p.length()] = isMatch(s.substr(j), p.substr(i + 2)))
						return 1;
					for (; j < s.length(); j++)
					{
						if (f[s.length()][p.length()] = isMatch(s.substr(j + 1), p.substr(i + 2)))
							return 1;
					}
					if (j == s.length() && i == p.length() - 2)
						return f[s.length()][p.length()] = 1;
					return f[s.length()][p.length()] = 0;
				}
				else
				{
					if (f[s.length()][p.length()] = isMatch(s.substr(j), p.substr(i + 2)))
						return  1;
					for (; s[j] == p[i]; j++)
					{
						if (f[s.length()][p.length()] = isMatch(s.substr(j + 1), p.substr(i + 2)))
							return 1;
					}
					if (j == s.length() && i == p.length() - 2)
						return f[s.length()][p.length()] = 1;
					return f[s.length()][p.length()] = 0;
				}
			}

			if (j >= s.length())
				return f[s.length()][p.length()] = 0;

			if (s[j] == p[i] || p[i] == '.')
				j++;
			else
				return f[s.length()][p.length()] = 0;
		}

		if ((s[j] == p[i] || p[i] == '.') && j == s.length() - 1)
			return f[s.length()][p.length()] = 1;
		return f[s.length()][p.length()] = 0;

	}
};



int main()
{
	Solution5 s1;

	cout << endl;
	cout << endl << s1.isMatch("aa", "a") << endl;
	cout << endl << s1.isMatch("aabcbcbcaccbcaabc", ".*aa*.c*.*a*") << endl;
	cout << endl << s1.isMatch("aasdfasdfasdfasdfas", "aasdf.*asdf.*asdf.*asdf.*s") << endl;
	cout << endl;
}