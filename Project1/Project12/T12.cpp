#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	//5種呈現，再分s2是不是空值的情況
	string roman(char c1, char c2, int i)
	{
		string ans = "";
		switch (i)
		{
		case 0:
			ans = ans + c1 + c2;
			break;
		case 1:
			ans = ans + c2;
			break;
		case 2:
			ans = ans + c2 + c1;
			break;
		case 3:
			ans = ans + c2 + c1 + c1;
			break;
		case 4:
			ans = ans + c2 + c1 + c1 + c1;
			break;
		default:
			break;
		}

		return ans;
	}

	string roman(char c1, int i)
	{
		string ans = "";
		switch (i)
		{
		case 2:
			ans = ans + c1;
			break;
		case 3:
			ans = ans + c1 + c1;
			break;
		case 4:
			ans = ans + c1 + c1 + c1;
			break;
		default:
			break;
		}
		return ans;
	}

	string intToRoman(int num) {
		string s = "IVXLCDM";
		string ans = "";
		int i = 0, j = 0, k = 0;
		//	i for I,X,C,M
		//	j for telling 0~3,4~8,9
		//	k for 5 mode
		while (num > 0)
		{
			k = (((num + 1) % 10) % 5);
			j = (((num % 10) + 1) / 5);
			//只有j在0時才會有空值(0~3)
			if (j == 0)
				ans = roman(s[i], k) + ans;
			else
				ans = roman(s[i], s[i + j], k) + ans;
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