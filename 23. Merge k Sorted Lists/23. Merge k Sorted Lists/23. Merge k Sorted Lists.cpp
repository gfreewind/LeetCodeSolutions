// 23. Merge k Sorted Lists.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <set>

using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

static bool list_node_less(const ListNode *n1, const ListNode *n2)
{
	if (n1 == NULL) {
		return true;
	}
	if (n2 == NULL) {
		return true;
	}

	return (n1->val < n2->val);
}

struct ListNodeComp {
	bool operator() (const ListNode* lhs, const ListNode* rhs) const
	{
		return list_node_less(lhs, rhs);
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		multiset<ListNode*, ListNodeComp> clists;
		ListNode *head = NULL;
		ListNode *cur = NULL;
		ListNode *next = NULL;

		for (auto it = lists.begin(); it != lists.end(); ++it) {
			cur = *it;
			if (cur) {
				clists.insert(cur);
			}
		}

		if (!clists.size()) {
			return NULL;
		}

		auto it = clists.begin();
		head = *it;
		cur = *it;

		clists.erase(it);
		next = cur->next;
		if (next) {
			clists.insert(next);
		}

		while (clists.size()) {
			auto it = clists.begin();
			cur->next = *it;
			cur = *it;
			next = cur->next;
			clists.erase(it);
			if (!clists.size()) {
				break;
			}
			if (next) {
				clists.insert(next);
			}
		}

		return head;

	}
};

int main()
{
    return 0;
}

