// 100. Same Tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/**
* Definition for a binary tree node.
*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!(p && q)) {
			return (p == q);
		}

		if (p->val != q->val) {
			return false;
		}

		TreeNode *pl, *ql;
		pl = p->left;
		ql = q->left;

		if (!isSameTree(pl, ql)) {
			return false;
		}

		TreeNode *pr, *qr;
		pr = p->right;
		qr = q->right;
		if (!isSameTree(pr, qr)) {
			return false;
		}

		return true;
	}
};


int main()
{
	TreeNode p1(0), p2(-5);
	TreeNode q1(0), q2(-8);

	p1.left = &p2;
	q1.left = &q2;

	Solution s;
	bool ret = s.isSameTree(&p1, &q1);

    return 0;
}

