#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *S = new ListNode();
		
		if (l1 == nullptr && l2 != nullptr)
			l1 = new ListNode();

		if (l1 != nullptr && l2 == nullptr)
			l2 = new ListNode();

		S->val = l1->val + l2->val;

		if (S->val >= 10)
		{
			S->val -= 10;
			S->next = new ListNode(1);
		}

		if (l1->next != nullptr)
			S->next = addTwoNumbers(S->next, l1->next);
		if (l2->next != nullptr)
			S->next = addTwoNumbers(S->next, l2->next);

		return S;

	}
};

//class Solution2 {
//public:
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		ListNode *S = new ListNode();
//		ListNode *Temp = new ListNode();
//		long total = 0;			//不給用整數去處理
//		Temp = l1;
//		for (int i = 0;Temp != nullptr; i++)
//		{
//			total += Temp->val * pow(10, i);
//			Temp = Temp->next;
//		}
//		Temp = l2;
//		for (int i = 0; Temp != nullptr; i++)
//		{
//			total += Temp->val * pow(10, i);
//			Temp = Temp->next;
//		}
//		Temp = S;
//		for (int i = 0; total !=0; i++)
//		{
//			Temp->val = total % 10;
//			total /= 10;
//			if (total != 0)
//			{
//				Temp->next = new ListNode();
//				Temp = Temp->next;
//			}
//		}
//
//		return S;
//	}
//};


class Solution3 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *S = new ListNode();
		ListNode *Temp = new ListNode();
		unordered_map<int, int> total;
		Temp = l1;
		for (int i = 0; Temp != nullptr; i++)
		{
			total[i] = Temp->val;
			Temp = Temp->next;
		}
		Temp = l2;
		for (int i = 0; Temp != nullptr; i++)
		{
			total[i] += Temp->val;
			Temp = Temp->next;
		}
		Temp = S;
		for (int i = 0; total.count(i); i++)
		{
			if (total[i] > 9)
			{
				total[i] -= 10;
				total[i + 1] += 1;
			}
			Temp->val = total[i];
			if (total.count(i + 1))
			{
				Temp->next = new ListNode();
				Temp = Temp->next;
			}
		}

		return S;
	}
};

class Solution3Plus {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *S = new ListNode();
		ListNode *Temp = new ListNode();
		unordered_map<int,int> total ;

		//L1跟L2不用TEMP直接用完進下一個NODE
		for (int i = 0; l1 != nullptr; i++)
		{
			total[i] = l1->val ;
			l1 = l1->next;
		}
		for (int i = 0; l2 != nullptr; i++)
		{
			total[i] += l2->val ;
			l2 = l2->next;
		}

		Temp = S;
		for (int i = 0; total.count(i) ; i++)
		{
			if (total[i] > 9)
			{
				total[i] -= 10;
				total[i + 1] += 1;
			}
			Temp->val = total[i];
			if (total.count(i+1))
			{
				Temp->next = new ListNode();
				Temp = Temp->next;
			}
		}

		return S;
	}
};


int main()
{
	Solution S1;
	//Solution2 S2;
	Solution3 S3;
	Solution3Plus S3p;
	ListNode l1(1);
	l1.next = new ListNode(3, new ListNode(5));
	ListNode l2(2,new ListNode(1,new ListNode(9,new ListNode(7))));
	ListNode *l3;
	//135+2197
	l3 = S1.addTwoNumbers(&l1, &l2);
	//l3 = S2.addTwoNumbers(&l1, &l2);
	l3 = S3.addTwoNumbers(&l1, &l2);
	l3 = S3p.addTwoNumbers(&l1, &l2);

	cout << endl;
	cout << endl;
}