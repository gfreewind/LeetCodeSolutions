// 206. Reverse Linked List.cpp : 定义控制台应用程序的入口点。
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
	ListNode* reverseList(ListNode* head) {
		ListNode *p1, *p2, *p3;
	
		p3 = NULL;
		p1 = head;

		while (p1) {
			p2 = p1->next;
			if (!p2) {
				p1->next = p3;
				return p1;
			}
			p1->next = p3;
			p3 = p2->next;
			p2->next = p1;
			p1 = p3;
			p3 = p2;
		}

		return p3;

	}
};


int main()
{
    return 0;
}

