#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

//直接全部都用遞迴
//相比只對有*時才做遞迴程式碼會好看很多
//並且全部都遞迴時可以用Fibonacci加速
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();

		bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

		if (p.length() >= 2 && p[1] == '*')
		{
			bool out_bReturn = false;

			//如果*多餘0個的結果不符合，那就是看看0個的
			if (first_match && isMatch(s.substr(1), p))
			{
				out_bReturn = true;
			}
			else
			{
				out_bReturn = isMatch(s, p.substr(2));
			}
			return out_bReturn;
		}
		else
		{
			return first_match && isMatch(s.substr(1), p.substr(1));
		}
	}
};


//更簡化
class Solution2 {
public:
	bool isMatch(string s, string p) {
		if (p.empty())
			return s.empty();
		bool fchar = (!s.empty() && ((p[0] == s[0]) || (p[0] == '.')));
		if (p.length() >= 2 && p[1] == '*')
			return (isMatch(s, p.substr(2)) || (fchar && isMatch(s.substr(1), p)));
		//zero or more char matches, therefore 1
		//and first char matches, so send from second into matching same pattern
		else
			return fchar && isMatch(s.substr(1), p.substr(1));
		//simplest case, matching char one by one
	}
};



//邏輯符合正規表達示
//直接使用功能
class Solution3 {
public:
	bool isMatch(string s, string p) {
		return regex_match(s, regex(p));
	}
};


//一次將全部結果算出來
class Solution4 {
public:
	bool isMatch(string s, string p) {
		const int n = s.size(), m = p.size();
		vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (j > 1 && p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 2];
					if (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
						dp[i][j] = dp[i][j] || dp[i - 1][j];
					}
				}
			}
		}
		return dp[n][m];
	}
};


//Fibonacci加速
class Solution5 {
public:

	int DP[32][32];  // <- this is our cache

	/*
		The solver function - accepts s, p, and corresponding indices i and j.
		Both i and j point to characters in s and p THAT SUCCEED THE CURRENT ONES
		I.e. isMatch(s, p, 3, 2) will process s[2] and p[1].
		This is needed to handle the edge case when i == 0 or j == 0
	*/
	bool isMatch(const string& s, const string& p, int i, int j) {
		if (DP[i][j] != -1) {
			// we have a cached result, so just return it!
			return DP[i][j];
		}

		if (i == 0) {
			// s is empty - so p must be full of wildcards in this case:
			if (p[j - 1] == '*') {
				return DP[i][j] = isMatch(s, p, i, j - 2);
			}
			else {
				// otherwise it doesn't match an empty string
				return DP[i][j] = false;
			}
		}

		if (p[j - 1] == '.' || s[i - 1] == p[j - 1]) {
			// if last characters match, we move one character back in both the pattern and the string:
			return DP[i][j] = isMatch(s, p, i - 1, j - 1);
		}

		if (p[j - 1] == '*') {
			// if it's a wildcard:
			if (p[j - 2] == '.' || s[i - 1] == p[j - 2]) {
				/* if the wildcard char matches the current string char, there are 3 ways:
				   1. Ignore the wildcard - go 2 characters back in the pattern
				   2. Ignore the match - go 1 character back in the string
				   3. Accept the wildcard - go 2 characters back in the pattern and 1 character back in the string
				*/
				return DP[i][j] = isMatch(s, p, i, j - 2) || isMatch(s, p, i - 1, j) || isMatch(s, p, i - 1, j - 2);
			}
			// The wildcard does not match - so we have to ignore it. Going 2 characters back in the pattern
			return DP[i][j] = isMatch(s, p, i, j - 2);
		}

		// We've tried all we could. No match by default.
		return DP[i][j] = false;
	}

	bool isMatch(const string& s, const string& p) {
		// Initializing the cache with -1
		for (int i = 0; i < 32; ++i) {
			DP[i][0] = false;
			for (int j = 1; j < 32; ++j) {
				DP[i][j] = -1;
			}
		}

		DP[0][0] = true;

		// Calling the solver
		return isMatch(s, p, s.length(), p.length());
	}
};

static const auto lowut02 = []() {ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); return nullptr; }();





//[演算法] Fibonacci：善用 cache 和 Memoization 提升程式效能
//https://pjchender.blogspot.com/2017/09/fibonacci-cache-memoization.html

