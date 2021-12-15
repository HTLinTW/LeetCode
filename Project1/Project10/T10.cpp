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

//�������j���
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

//Fibonacci�[�t
class Solution3 {
public:
	//s�Pp���d�򭭨�
	//���M�ݭn�Ψ�ʺA�}�C
	//�]�����j�ҥH�n��b��ƥ~
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


//Fibonacci�����x�}��X�ӫ�
//���m����������
//�]����������ҥH�z�פW�|��Solution3���[�t�C
class Solution4 {
public:

	bool isMatch(string s, string p) {
		//�@�}�lINIT�N�������X��
		//���λ��j�ҥH�i�H������̭�
		//���D�|���ƥΦA���~��
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



//�쥻�g���޿��Fibonacci�[�t����
//�u�n�����j�N�i�H��Fibonacci�[�t
//�ҥH���j���ܤ��n�g�o�ӽ���
//�g²��@�I�M���Fibonacci�[�t�|��n�z��
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