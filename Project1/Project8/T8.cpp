#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int myAtoi(string s) {
		int start;
		string temp = "";
		long ans = 0;
		if (s.length() == 0)
			return 0;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ' && temp.length() == 0)
			{
				continue;
			}
			else if (temp.length() == 0)
			{
				if (s[i] == '-')
					temp += s[i];
				else if (s[i] == '+')
					temp += '0';
				else if (s[i] < 58 && s[i] > 47)
					temp += s[i];
				else
					return 0;
			}
			else if (s[i] > 57 || s[i] < 48)
			{
				break;
			}
			else
				temp += s[i];
		}


		if (temp == "")
			return 0;
		else if (temp[0] != '-')
			ans = temp[0] - 48;

		for (int i = 1; i < temp.length(); i++)
		{
			ans = ((ans) * 10 + (temp[i] - 48));
			if (ans > pow(2, 31) - 1)
			{
				ans = pow(2, 31) - 1;
				if (temp[0] == '-')
					ans = pow(2, 31);
				else
					ans = pow(2, 31) - 1;
				break;
			}
		}

		if (temp[0] == '-')
			ans = -ans;

		return (int)ans;

	}
};

int main()
{
	Solution s1;

	cout << endl;
	cout << endl << s1.myAtoi(" ") << endl;
	cout << endl;
}