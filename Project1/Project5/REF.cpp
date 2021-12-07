#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//當有字元前後字元重複時就開始檢查迴文
//另外如果有重複字元
//那就一定會出現迴文
//然後已重複字元的前後開始檢查
//並且檢查完後可以跳過
//這地方會加速很多
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty()) return "";
		if (s.size() == 1) return s;
		int min_start = 0, max_len = 1;
		for (int i = 0; i < s.size();) {
			if (s.size() - i <= max_len / 2) break;
			int j = i, k = i;
			while (k < s.size() - 1 && s[k + 1] == s[k]) ++k; // Skip duplicate characters.
			i = k + 1;
			while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
			int new_len = k - j + 1;
			if (new_len > max_len) { min_start = j; max_len = new_len; }
		}
		return s.substr(min_start, max_len);
	}
};


//與上面邏輯一樣
class Solution2 {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2)
			return s;
		int len = 0;
		int start = 0, i = 0;
		while (i < s.size()) {
			int left = i;
			int right = i;
			while (right < s.size() - 1 && s[right] == s[right + 1])
				right++;
			i = right + 1;
			while (right < s.size() - 1 && left > 0 && s[right + 1] == s[left - 1])
				right++, left--;
			int new_len = right - left + 1;
			if (new_len > len) {
				start = left;
				len = new_len;
			}
		}
		return s.substr(start, len);
	}
};
