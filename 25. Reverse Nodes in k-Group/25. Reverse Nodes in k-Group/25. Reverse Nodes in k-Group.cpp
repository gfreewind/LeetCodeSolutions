// 25. Reverse Nodes in k-Group.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>

using namespace std;

/**
* Definition for singly-linked list.
* 
**/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverse_nth_nodes(ListNode *head, int n, int* reverse_cnt, ListNode** tail)
	{
			
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode *nh;
		ListNode *tail;
		ListNode *cur;
		ListNode *ret;
		ListNode *last;
		int reverse_cnt;

		if (!head || k <= 1) {
			return head;
		}

		nh = tail = NULL;
		cur = head;
		last = NULL;
		do {
			ret = reverse_nth_nodes(cur, k, &reverse_cnt, &tail);
			if (reverse_cnt < k) {
				ret = reverse_nth_nodes(ret, k, &reverse_cnt, &tail);
				if (!nh) {
					nh = ret;
				}
				break;
			}
			if (last) {
				last->next = ret;
			}
			last = tail;
			if (!nh) {
				nh = ret;
			}
			cur = tail->next;
		} while (cur);

		return nh;
	}
};


int main()
{
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	int reverse_cnt;

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	Solution s;

	ListNode *ret = &n1;
	ListNode *tail;

	ret = s.reverse_nth_nodes(ret, 5, &reverse_cnt, &tail);
	ret = s.reverse_nth_nodes(ret, 6, &reverse_cnt, &tail);
	ret = s.reverse_nth_nodes(ret, 2, &reverse_cnt, &tail);
	ret = s.reverse_nth_nodes(ret, 2, &reverse_cnt, &tail);
	ret = s.reverse_nth_nodes(ret, 3, &reverse_cnt, &tail);
	ret = s.reverse_nth_nodes(ret, 3, &reverse_cnt, &tail);
	ret = s.reverse_nth_nodes(ret, 4, &reverse_cnt, &tail);
	ret = s.reverse_nth_nodes(ret, 4, &reverse_cnt, &tail);

	ret = s.reverseKGroup(ret, 2);
	ret = s.reverseKGroup(ret, 2);
	ret = s.reverseKGroup(ret, 3);
	ret = s.reverseKGroup(ret, 3);
	ret = s.reverseKGroup(ret, 6);


    return 0;
}

