#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	string mixF(char s1, char s2, int i)
	{
		string ans = "";
		switch (i)
		{
		case 0:
			ans = ans + s1 + s2;
			break;
		case 1:
			ans = ans + s2;
			break;
		case 2:
			ans = ans + s2 + s1;
			break;
		case 3:
			ans = ans + s2 + s1 + s1;
			break;
		case 4:
			ans = ans + s2 + s1 + s1 + s1;
			break;
		default:
			break;
		}
		return ans;
	}

	string mixF(char s1, int i)
	{
		string ans = "";
		switch (i)
		{
		case 0:
			ans = ans + s1;
			break;
		case 1:
			ans = ans;
			break;
		case 2:
			ans = ans + s1;
			break;
		case 3:
			ans = ans + s1 + s1;
			break;
		case 4:
			ans = ans + s1 + s1 + s1;
			break;
		default:
			break;
		}
		return ans;
	}

	string intToRoman(int num) {
		string s = " IVXLCDM";
		string ans = "";
		int i = 0, j = 0, k = 0;
		while (num > 0)
		{
			k = (((num + 1) % 10) % 5);
			j = (((num % 10) + 1) / 5);
			if (j == 0)
				ans = mixF(s[i + 1], k) + ans;
			else
				ans = mixF(s[i + 1], s[i + j + 1], k) + ans;
			num /= 10;
			i += 2;
		}
		return ans;
	}
};


int main()
{
	Solution s;

	cout << endl;
	cout << endl << s.intToRoman(1994) << endl;
	cout << endl;
}