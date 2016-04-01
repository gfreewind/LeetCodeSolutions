// 23. Merge k Sorted Lists.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <set>
#include <queue>
#include <deque>

using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
     int val;
     ListNode *next;
	 ListNode():val(0),next(NULL) {}
     ListNode(int x) : val(x), next(NULL) {}
};

static bool list_node_great(const ListNode *n1, const ListNode *n2)
{
	if (n1 == NULL) {
		return false;
	}
	if (n2 == NULL) {
		return false;
	}

	return (n1->val > n2->val);
}

struct ListNodeComp {
	bool operator() (const ListNode* lhs, const ListNode* rhs) const
	{
		return list_node_great(lhs, rhs);
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, ListNodeComp> cqueue;
		ListNode *head = NULL;
		ListNode *cur = NULL;
		ListNode *next = NULL;

		for (auto it = lists.begin(); it != lists.end(); ++it) {
			cur = *it;
			if (cur) {
				cqueue.push(cur);
			}
		}

		if (!cqueue.size()) {
			return NULL;
		}


		head = cqueue.top();
		cur = head;

		cqueue.pop();
		next = cur->next;
		if (next) {
			cqueue.push(next);
		}

		while (cqueue.size()) {
			cur->next = cqueue.top();
			cqueue.pop();
			cur = cur->next;
			next = cur->next;
			if (!cqueue.size()) {
				break;
			}
			if (next) {
				cqueue.push(next);
			}
		}

		return head;

	}
};

int main()
{
	ListNode nodes1[3];
	ListNode nodes2[3];

	nodes1[0].val = 1;
	nodes1[0].next = nodes1 + 1;
	nodes1[1].val = 2;
	nodes1[1].next = nodes1 + 2;
	nodes1[2].val = 2;
	nodes1[2].next = NULL;

	nodes2[0].val = 1;
	nodes2[0].next = nodes2 + 1;
	nodes2[1].val = 1;
	nodes2[1].next = nodes2 + 2;
	nodes2[2].val = 2;
	nodes2[2].next = NULL;

	vector<ListNode*> v;
	v.push_back(nodes1);
	v.push_back(nodes2);

	Solution s;
	ListNode *n = s.mergeKLists(v);


    return 0;
}

