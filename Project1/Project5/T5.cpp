#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

//���ۼg�M����L�Ӽg�����e���@�˺٬��j��palindromic 
class Solution {
public:
	string longestPalindrome(string s) {
		int length = 1, tempHalfLength;
		string ans = "";
		//�����_�P����
		//�q�ĤG�r���}�l
		//�p�G�k���٨S�ˬd�����קC��ثe�̤j���ת��@�b�A�N�i�H���F
		for (int i = 1; i < s.length() - (length + 1) / 2; i++)
		{
			tempHalfLength = 1;
			//�j��b�|�̪����|�W�L�ˬd�r������䪺�̵u�Z��
			while (tempHalfLength < i + 1 && tempHalfLength <= s.length() - i)
			{
				if (s[i - tempHalfLength] == s[i + tempHalfLength])
				{
					tempHalfLength++;
				}
				else
				{
					break;
				}
			}
			//�b�|�W�L�Z���άO���䤣�ۦP��
			//�h�^�h�@��N�O�n���j��
			tempHalfLength--;
			if (length < tempHalfLength * 2 + 1)
			{
				length = tempHalfLength * 2 + 1;
				ans = s.substr(i - tempHalfLength, length);
			}
		}

		for (int i = 0; i < s.length() - (length - 1) / 2; i++)
		{
			tempHalfLength = 1;
			while (tempHalfLength <= i + 1 && tempHalfLength <= s.length() - i)
			{
				if (s[i - tempHalfLength + 1] == s[i + tempHalfLength])
				{
					tempHalfLength++;
				}
				else
				{
					break;
				}
			}
			tempHalfLength--;
			if (length < tempHalfLength * 2)
			{
				length = tempHalfLength * 2;
				ans = s.substr(i - tempHalfLength + 1, length);
			}
		}

		if (s.length() == 1 || length == 1)
			ans = s[0];

		return ans;
	}
};


//�r�������P�~���ɦr��
//�o�˴N���|�O���
//���t�פ��|�����....
//������j�媺�����ܦh�F
class Solution2 {
public:
	string longestPalindrome(string s) {
		int length = 1, tempHalfLength;
		string ans = "", newstr = " ";

		for (int i = 0; i < s.length(); i++)
		{
			newstr += s[i];
			newstr += " ";
		}

		//�u����
		//�q�ĤG�r���}�l
		//�p�G�k���٨S�ˬd�����קC��ثe�̤j���ת��@�b�A�N�i�H���F
		for (int i = 2; i < newstr.length() - length; i++)
		{
			tempHalfLength = 1;
			//�j��b�|�̪����|�W�L�ˬd�r������䪺�̵u�Z��
			while (tempHalfLength < i + 1 && tempHalfLength <= newstr.length() - i)
			{
				if (newstr[i - tempHalfLength] == newstr[i + tempHalfLength])
				{
					tempHalfLength++;
				}
				else
				{
					break;
				}
			}
			tempHalfLength--;
			if (length < tempHalfLength )
			{
				length = tempHalfLength ;
				ans = s.substr((i - tempHalfLength) / 2, length);
			}
		}


		if (s.length() == 1 || length == 1)
			ans = s[0];

		return ans;
	}
};


int main()
{
	Solution2 s1;
	string str = "bb";

	cout << endl;
	cout << endl << s1.longestPalindrome(str) << endl;
	cout << endl;
}