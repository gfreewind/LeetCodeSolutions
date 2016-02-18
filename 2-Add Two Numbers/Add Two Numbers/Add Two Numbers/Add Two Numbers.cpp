// Add Two Numbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *ret = NULL;
		ListNode *last = NULL;
		ListNode *cur;
		
		int o = 0;
		while (l1 || l2 || o) {
			int s = 0;

			if (l1) {
				s = l1->val;
				l1 = l1->next;
			}
			if (l2) {
				s += l2->val;
				l2 = l2->next;
			}
			s += o;
			if (s >= 10) {
				s -= 10;
				o = 1;
			}
			else {
				o = 0;
			}

			cur = new ListNode(s);
			if (last) {
				last->next = cur;
				last = cur;
			}
			else {
				ret = last = cur;
			}
		}

		return ret;
	}
};

int main()
{
    return 0;
}

