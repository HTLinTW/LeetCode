#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans = {};

		for (int i = 0; i < nums.size() - 2; i++)
		{
			for (int j = i + 1; j < nums.size() - 1; j++)
			{
				std::vector<int>::iterator it;
				it = std::find(nums.begin() + j, nums.end(), -nums[i] - nums[j]);
				if (it != nums.end())
				{

					ans.push_back({ nums[i],nums[j],*it });
				}
			}
		}

		return ans;
	}
};

//vector��FIND�ɶ���ƬON
//����ɶ�����N^3
//�]���|�W�L�ɶ�
class Solution3 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return {};
		vector<vector<int>> ans = {};
		multiset<int> settemp(nums.begin(), nums.end());
		vector<int> temp(settemp.begin(), settemp.end());
		//�i�H��std::sort(nums.begin(), nums.end());	�h�ƦC

		for (int i = 0; i < temp.size() - 2; i++)
		{
			try
			{
				if (temp[i] == temp.at(i - 1))
					continue;
			}
			catch (exception &e)
			{
			}
			for (int j = i + 1; j < temp.size() - 1; j++)
			{
				if (temp[j] == temp[j - 1] && j != i + 1)
					continue;
				std::vector<int>::iterator it = std::find(temp.begin() + j + 1, temp.end(), -temp[i] - temp[j]);
				if (it != temp.end())
					ans.push_back({ temp[i],temp[j],*it });
			}
		}
		return ans;
	}
};

//�����t
class Solution4 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return {};
		vector<vector<int>> ans = {};
		multiset<int> p = {}, m = {};
		int temp1 = 0, temp2 = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < 0)
				m.insert(nums[i]);
			else
				p.insert(nums[i]);
		}

		if (p.size() == 0)
			return {};
		else if (p.count(0) > 2)
			ans.push_back({ 0,0,0 });

		for (auto i = m.begin(); i != m.end(); i++)
		{
			auto j = i;
			j++;
			temp2 = 0;
			for (; j != m.end(); j++)
			{
				if (p.count(-*i - *j) > 0 && temp1 != *i && temp2 != *j)
					ans.push_back({ *i,*j,-*i - *j });
				temp2 = *j;
			}
			temp1 = *i;
		}

		temp1 = -1;
		for (auto i = p.begin(); i != p.end(); i++)
		{
			auto j = i;
			j++;
			temp2 = -1;
			for (; j != p.end(); j++)
			{
				if (m.count(-*i - *j) > 0 && temp1 != *i && temp2 != *j)
					ans.push_back({ -*i - *j,*i,*j });
				temp2 = *j;
			}
			temp1 = *i;
		}


		return ans;
	}
};


//��map�ˬd
class Solution5 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return {};
		vector<vector<int>> ans = {};
		multiset<int> p = {}, m = {};
		unordered_map<int, int> mp = {}, mm = {};
		int temp1 = 0, temp2 = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < 0)
			{
				if (mm[nums[i]] < 3)
				{
					if (mm[nums[i]] == 0)
					{
						mm[nums[i]] = 1;
						m.insert(nums[i]);
					}
					else
					{
						mm[nums[i]] += 1;
						m.insert(nums[i]);
					}
				}
			}
			else
			{
				if (mp[nums[i]] < 3)
				{
					if (mp[nums[i]] == 0)
					{
						mp[nums[i]] = 1;
						p.insert(nums[i]);
					}
					else
					{
						mp[nums[i]] += 1;
						p.insert(nums[i]);
					}
				}
			}
		}

		if (p.size() == 0)
			return {};
		else if (p.count(0) > 2)
			ans.push_back({ 0,0,0 });

		for (auto i = m.begin(); i != m.end(); i++)
		{
			auto j = i;
			j++;
			temp2 = 0;
			for (; j != m.end(); j++)
			{
				if (p.count(-*i - *j) > 0 && temp1 != *i && temp2 != *j)
					ans.push_back({ *i,*j,-*i - *j });
				temp2 = *j;
			}
			temp1 = *i;
		}

		temp1 = -1;
		for (auto i = p.begin(); i != p.end(); i++)
		{
			auto j = i;
			j++;
			temp2 = -1;
			for (; j != p.end(); j++)
			{
				if (m.count(-*i - *j) > 0 && temp1 != *i && temp2 != *j)
					ans.push_back({ -*i - *j,*i,*j });
				temp2 = *j;
			}
			temp1 = *i;
		}


		return ans;
	}
};



//������map
class Solution6 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return {};
		vector<vector<int>> ans = {};
		map<int, int> mp = {}, mm = {};
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < 1)
			{
				if (mm[nums[i]] < 3)
				{
					if (mm[nums[i]] == 0)
						mm[nums[i]] = 1;
					else
						mm[nums[i]] += 1;
				}
			}
			else
			{
				if (mp[nums[i]] < 3)
				{
					if (mp[nums[i]] == 0)
						mp[nums[i]] = 1;
					else
						mp[nums[i]] += 1;
				}
			}
		}

		if (mm.size() == 0)
			return {};

		for (auto i = mm.begin(); i != mm.end(); i++)
		{
			auto j = i;
			//�@�w�n��()�~��.�Xfirst
			if ((*i).second == 1)
				j++;
			for (; j != mm.end(); j++)
			{
				if (mp.count(-(*i).first - (*j).first) > 0)
					ans.push_back({ (*i).first,(*j).first,-(*i).first - (*j).first });
			}
		}

		if (mm[0] > 2)
			ans.push_back({ 0,0,0 });

		for (auto i = mp.begin(); i != mp.end(); i++)
		{
			auto j = i;
			if ((*i).second == 1)
				j++;
			for (; j != mp.end(); j++)
			{
				if (mm.count(-(*i).first - (*j).first) > 0)
					ans.push_back({ (*i).first,(*j).first,-(*i).first - (*j).first });
			}
		}
		return ans;
	}
};

//���αƧǤ]�i�H
//�ҥH���unordered_map
//�[�W�U��
//MAP.COUNT���ɶ���ƬOO(N)
//����ɶ���Ƥj���O(N^3)/4�٬O��REF2��N^2
class Solution7 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return {};
		vector<vector<int>> ans = {};
		unordered_map<int, int> mp = {}, mm = {};
		int imax = 0, imin = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < 1)
			{
				if (mm[nums[i]] < 3)
				{
					mm[nums[i]] += 1;
					imin = min(imin, nums[i]);
				}
			}
			else
			{
				if (mp[nums[i]] < 3)
				{
					mp[nums[i]] += 1;
					imax = max(imax, nums[i]);
				}
			}
		}

		if (mm.size() == 0)
			return {};

		for (auto i = mm.begin(); i != mm.end(); i++)
		{
			if (imax < -(*i).first)
				continue;
			auto j = i;
			//�@�w�n��()�~��.�Xfirst
			if ((*i).second == 1)
				j++;
			for (; j != mm.end(); j++)
			{
				if (imax < -(*i).first - (*j).first)
					continue;
				if (mp.count(-(*i).first - (*j).first) > 0)
					ans.push_back({ (*i).first,(*j).first,-(*i).first - (*j).first });
			}
		}

		//�n��b�o��A���M�|�]���ϥ�mm[0]�Ӳ���{0,0}�����
		if (mm[0] > 2)
			ans.push_back({ 0,0,0 });

		for (auto i = mp.begin(); i != mp.end(); i++)
		{
			if (-imin < (*i).first)
				continue;
			auto j = i;
			if ((*i).second == 1)
				j++;
			for (; j != mp.end(); j++)
			{
				if (-imin < (*i).first + (*j).first)
					continue;
				if (mm.count(-(*i).first - (*j).first) > 0)
					ans.push_back({ (*i).first,(*j).first,-(*i).first - (*j).first });
			}
		}
		return ans;
	}
};


//���map.find�O�ζ¬���h��A�ɶ���ƬOO(LogN)
//�������ӬOO((N^2*LogN)/2)
//�`�ɶ��ܤƦ��P
//����REF2��N^2
class Solution7p {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return {};
		vector<vector<int>> ans = {};
		unordered_map<int, int> mp = {}, mm = {};
		int imax = 0, imin = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] < 1)
			{
				if (mm[nums[i]] < 3)
				{
					mm[nums[i]] += 1;
					imin = min(imin, nums[i]);
				}
			}
			else
			{
				if (mp[nums[i]] < 3)
				{
					mp[nums[i]] += 1;
					imax = max(imax, nums[i]);
				}
			}
		}

		if (mm.size() == 0)
			return {};

		for (auto i = mm.begin(); i != mm.end(); i++)
		{
			if (imax < -(*i).first)
				continue;
			auto j = i;
			//�@�w�n��()�~��.�Xfirst
			if ((*i).second == 1)
				j++;
			for (; j != mm.end(); j++)
			{
				if (imax < -(*i).first - (*j).first)
					continue;
				if (mp.find(-(*i).first - (*j).first) != mp.end())
					ans.push_back({ (*i).first,(*j).first,-(*i).first - (*j).first });
			}
		}

		//�n��b�o��A���M�|�]���ϥ�mm[0]�Ӳ���{0,0}�����
		if (mm[0] > 2)
			ans.push_back({ 0,0,0 });

		for (auto i = mp.begin(); i != mp.end(); i++)
		{
			if (-imin < (*i).first)
				continue;
			auto j = i;
			if ((*i).second == 1)
				j++;
			for (; j != mp.end(); j++)
			{
				if (-imin < (*i).first + (*j).first)
					continue;
				if (mm.find(-(*i).first - (*j).first) != mm.end())
					ans.push_back({ (*i).first,(*j).first,-(*i).first - (*j).first });
			}
		}
		return ans;
	}
};





//�������t
//���פ@�˦�������X�ӿ��~�A�����
//���t�פW���Ӥ����t�����
class Solution8 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3)
			return {};
		vector<vector<int>> ans = {};
		unordered_map<int, int> mymap = {};
		unordered_set<int> myset = {};
		int imax = 0, imin = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (mymap[nums[i]] < 3)
			{
				mymap[nums[i]] += 1;
				imin = min(imin, nums[i]);
				imax = max(imax, nums[i]);
			}
		}

		if (mymap[0] > 2)
			ans.push_back({ 0,0,0 });
		else if (mymap[0] == 0)
			mymap.erase(0);

		for (auto i = mymap.begin(); i != mymap.end(); i++)
		{
			auto j = i;
			j++;
			//�@�w�n��()�~��.�Xfirst
			if((*i).second ==0)
				continue;
			for (; j != mymap.end(); j++)
			{
				if (imax < -(*i).first - (*j).first || -imin < (*i).first + (*j).first)
					continue;
				if (myset.count((*j).first) > 0)
					continue;
				if ((*j).second == 0)
					continue;
				//error
				//auto k = std::find(j, map.end(), -(*i).first - (*j).first);
				//if (k == map.end())
				//	continue;
				if ((-(*i).first - (*j).first) == (*i).first || (-(*i).first - (*j).first) == (*j).first)
				{
					if (mymap[(-(*i).first - (*j).first)] > 1)
					{
						ans.push_back({ (*i).first,(*j).first,-(*i).first - (*j).first });
						myset.insert((*j).first);
						myset.insert(-(*i).first - (*j).first);
					}
					continue;
				}
				if (mymap[(-(*i).first - (*j).first)] > 0)
				{
					ans.push_back({ (*i).first,(*j).first,-(*i).first - (*j).first });
					myset.insert((*j).first);
					myset.insert(-(*i).first - (*j).first);
				}
			}
			mymap[(*i).first] = 0;
			myset.clear();
		}
		return ans;
	}
};


int main()
{
	Solution7 s;
	vector<int> v = { 34,55,79,28,46,33,2,48,31,-3,84,71,52,-3,93,15,21,-43,57,-6,86,56,94,74,83,-14,28,-66,46,-49,62,-11,43,65,77,12,47,61,26,1,13,29,55,-82,76,26,15,-29,36,-29,10,-70,69,17,49 };

	cout << endl;
	cout << endl << s.threeSum(v)[0][0] << endl;
	cout << endl;
}