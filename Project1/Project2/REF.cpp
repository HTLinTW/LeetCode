#include <iostream>

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
		ListNode *newHead = new ListNode(0);
		ListNode *prev = newHead;
		int sum = 0, carry = 0;
		while (l1 != NULL || l2 != NULL) {

			int num1 = (l1 != NULL) ? l1->val : 0;

			int num2 = (l2 != NULL) ? l2->val : 0;

			sum = num1 + num2 + carry;

			carry = sum / 10;

			ListNode *temp = new ListNode(sum % 10);
			prev->next = temp;
			prev = temp;

			l1 = (l1 != NULL) ? l1->next : NULL;
			l2 = (l2 != NULL) ? l2->next : NULL;

		}

		if (carry > 0) {
			ListNode *temp = new ListNode(carry);
			prev->next = temp;
		}
		return newHead->next;
	}
};

//int main()
//{
//	Solution S1;
//	ListNode l1(1);
//	l1.next = new ListNode(3, new ListNode(5));
//	ListNode l2(2, new ListNode(1, new ListNode(9, new ListNode(7))));
//	ListNode *l3;
//	//135+2197
//	l3 = S1.addTwoNumbers(&l1, &l2);
//
//	cout << endl;
//	cout << endl;
//}