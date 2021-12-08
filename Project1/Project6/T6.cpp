#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		string ans = "";

		if (numRows == 0)
			return ans;
		else if (numRows == 1)
			return s;

		string * tempstr;
		tempstr = new string[numRows];

		for (int i = 0; i < s.length(); i++)
		{
			if (((i-1) / (numRows-1)) % 2)
			{
				if ((i % (numRows - 1)) == 0)
				{
					tempstr[0] += s[i];
					continue;
				}
				for (int j = 0; j < numRows; j++)
					tempstr[j] += " ";
				tempstr[numRows-1 - i % (numRows-1)].replace(tempstr[0].length()-1, 1,1, s[i]);
			}
			else
			{
				tempstr[i%((numRows-1)*2)] += s[i];
			}
		}
		for (int j = 0; j < numRows; j++)
		{
			ans += tempstr[j];
			ans += "\n";
		}
		return ans;
	}
};

//竟然不需要顯示空格和換行....
class Solution2 {
public:
	string convert(string s, int numRows) {
		string ans = "";

		if (numRows == 0)
			return ans;
		else if (numRows == 1)
			return s;

		string * tempstr;
		tempstr = new string[numRows];

		for (int i = 0; i < s.length(); i++)
		{
			if (((i - 1) / (numRows - 1)) % 2)
			{
				if ((i % (numRows - 1)) == 0)
				{
					tempstr[0] += s[i];
					continue;
				}
				tempstr[numRows - 1 - i % (numRows - 1)] += s[i];
			}
			else
			{
				tempstr[i % ((numRows - 1) * 2)] += s[i];
			}
		}
		for (int j = 0; j < numRows; j++)
		{
			ans += tempstr[j];
		}
		return ans;
	}
};

int main()
{

	Solution s1;
	string str = "1234567890";

	cout << endl;
	cout << endl << s1.convert(str, 3) << endl;
	cout << endl;
}
