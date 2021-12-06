#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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


// Time: O(N)
// Space: O(N)
class Solution3 {
public:
	string longestPalindrome(string s) {
		int N = s.size();
		string t = "^*";
		for (char c : s) {
			t += c;
			t += '*';
		}
		t += '$'; // inflating the `s` ( example: "abc" becomes "^*a*b*c*$" )
		int M = t.size();

		vector<int> r(M); // `r[i]` is the number of palindromes with `t[i]` as the center (aka. the radius of the longest palindrome centered at `t[i]`)
		r[1] = 1;
		int j = 1; // `j` is the index with the furthest reach `j + r[j]`
		for (int i = 2; i <= 2 * N; ++i) {
			int cur = j + r[j] > i ? min(r[2 * j - i], j + r[j] - i) : 1; // `t[2*j-i]` is the symmetry point to `t[i]`
			while (t[i - cur] == t[i + cur]) ++cur; // expanding the current radius
			if (i + cur > j + r[j]) j = i;
			r[i] = cur;
		}

		int len = 1, start = 0;
		for (int i = 2; i <= 2 * N; ++i) {
			if (r[i] - 1 > len) {
				len = r[i] - 1;
				start = (i - r[i]) / 2;
			}
		}
		return s.substr(start, len);
	}
};