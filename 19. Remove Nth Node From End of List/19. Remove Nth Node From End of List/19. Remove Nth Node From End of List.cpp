// 19. Remove Nth Node From End of List.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct ListNode {
     int val;
	 ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head) {
			return NULL;
		}

		if (n <= 0) {
			return head;
		}

		ListNode *fast, *slow;

		int i = 0;
		fast = slow = head;

		while (fast) {
			++i;
			if (i == n) {
				break;
			}
			fast = fast->next;
		}

		if (!fast) {
			return head;
		}

		ListNode *last = head;

		while (fast->next) {
			last = slow;
			slow = slow->next;
			fast = fast->next;
		};

		if (slow == head) {
			return last->next;
		}
		else {
			last->next = slow->next;
		}


		return head;
	}
};

static struct ListNode * test_func(struct ListNode *head, int n)
{
	Solution s;
	struct ListNode *ret = s.removeNthFromEnd(head, n);

	return ret;

}

int main()
{
	struct ListNode node1(1);
	struct ListNode node2(2);
	struct ListNode node3(3);
	struct ListNode node4(4);
	struct ListNode node5(5);

	node1.next = &node2;

	struct ListNode *node = test_func(&node1, 1);


    return 0;
}

