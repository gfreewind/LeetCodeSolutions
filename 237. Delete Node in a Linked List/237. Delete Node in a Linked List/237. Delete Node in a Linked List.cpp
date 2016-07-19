// 237. Delete Node in a Linked List.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		if (!node) {
			return;
		}

		ListNode *next = node->next;
		while (next->next) {
			node->val = next->val;
			node = next;
			next = next->next;
		}

		node->val = next->val;
		node->next = NULL;
	}
};

int main()
{
	ListNode n1(0), n2(1);
	n1.next = &n2;

	Solution s;
	s.deleteNode(&n1);

    return 0;
}

