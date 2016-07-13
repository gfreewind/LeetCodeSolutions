// 104. Maximum Depth of Binary Tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <stack>

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
	int maxDepth(TreeNode* root) {
		int depth = 0;

		if (!root) {
			return 0;
		}

		std::stack<TreeNode*> s;
		TreeNode *n = root;
		do {
			
		} while (n);

		return depth;

	}
};


int main()
{
	TreeNode n1(1), n2(2), n3(3);
	Solution s;

	int depth = s.maxDepth(&n1);
	
	n1.left = &n2;
	depth = s.maxDepth(&n1);

	n2.right = &n3;
	depth = s.maxDepth(&n1);



    return 0;
}

