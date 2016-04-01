// 24. Swap Nodes in Pairs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
     int val;
     ListNode *next;
	 ListNode():val(0),next(NULL){}
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *cur, *next, *tmp, *last;
		ListNode *new_head;

		if (!head) {
			return NULL;
		}
		if (!head->next) {
			return head;
		}

		new_head = head->next;
		cur = head;

		/* swap the first two node */
		next = cur->next;
		tmp = next->next;
		next->next = cur;
		cur->next = tmp;
		last = cur;

		do {
			cur = last->next;
			if (!cur) {
				break;
			}
			next = cur->next;
			if (!next) {
				break;
			}

			tmp = next->next;
			next->next = cur;
			cur->next = tmp;
			last->next = next;
			last = cur;
		} while (1);

		return new_head;
	}
};


int main()
{
	ListNode n1[2];
	n1[0].val = 1;
	n1[0].next = &n1[1];
	n1[1].val = 2;

	Solution s;
	ListNode *ret = s.swapPairs(n1);

	ListNode n2[3];
	n2[0].val = 1;
	n2[0].next = &n2[1];
	n2[1].val = 2;
	n2[1].next = &n2[2];
	n2[2].val = 3;
	ret = s.swapPairs(n2);

	ListNode n3[4];
	n3[0].val = 1;
	n3[0].next = &n3[1];
	n3[1].val = 2;
	n3[1].next = &n3[2];
	n3[2].val = 3;
	n3[2].next = &n3[3];
	n3[3].val = 4;
	ret = s.swapPairs(n3);

	ListNode n4[5];
	n4[0].val = 1;
	n4[0].next = &n4[1];
	n4[1].val = 2;
	n4[1].next = &n4[2];
	n4[2].val = 3;
	n4[2].next = &n4[3];
	n4[3].val = 4;
	n4[3].next = &n4[4];
	n4[4].val = 5;
	ret = s.swapPairs(n4);


    return 0;
}

