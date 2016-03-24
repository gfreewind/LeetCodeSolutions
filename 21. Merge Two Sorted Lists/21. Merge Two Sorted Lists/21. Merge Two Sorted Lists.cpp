// 21. Merge Two Sorted Lists.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/**
* Definition for singly-linked list.
*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *cur1;
		ListNode *cur2;
		ListNode *head3, *cur3;

		if (!l1) {
			return l2;
		}
		if (!l2) {
			return l1;
		}

		if (l1->val <= l2->val) {
			head3 = l1;
			cur1 = l1->next;
			cur2 = l2;
		}
		else {
			head3 = l2;
			cur1 = l1;
			cur2 = l2->next;
		}

		cur3 = head3;
		do {
			if (!cur1) {
				cur3->next = cur2;
				break;
			}
			if (!cur2) {
				cur3->next = cur1;
				break;
			}

			if (cur1->val <= cur2->val) {
				cur3->next = cur1;
				cur1 = cur1->next;
			}
			else {
				cur3->next = cur2;
				cur2 = cur2->next;
			}
			cur3 = cur3->next;
		} while (cur1 || cur2);

		return head3;
	}
};

int main()
{
    return 0;
}

