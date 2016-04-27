// 32. Longest Valid Parentheses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.size() == 0) {
			return 0;
		}

		int max_len = 0;
		vector<bool> match(s.size(), false);
		stack<int> index;
		// Check the parenthese validity
		for (uint32_t i = 0; i < s.size(); ++i) {
			if ('(' == s[i]) {
				index.push(i);
			}
			else if (')' == s[i]) {
				if (!index.empty()) {
					match[index.top()] = true;
					index.pop();
					match[i] = true;
				}
			}
		}
		// check the longest valid parenthese
		int cur_len = 0;
		for (uint32_t i = 0; i < s.size(); ++i) {
			if (match[i]) {
				cur_len++;
			}
			else {
				if (cur_len > max_len) {
					max_len = cur_len;
				}
				cur_len = 0;
			}
		}

		if (cur_len > max_len) {
			max_len = cur_len;
		}

		return max_len;
	}
};

static void test_func(string &ss, int expect)
{
	Solution s;
	int ret = s.longestValidParentheses(ss);

	cout << "The longest parentheses of " << ss << "is " << ret;
	if (ret != expect) {
		cout << ", not expected!!!";
	}
	cout << endl;

}

int main()
{
	string s;

	test_func(s, 0);

	s = "(()";
	test_func(s, 2);

	s = ")()())";
	test_func(s, 4);

	s = "(()((())";
	test_func(s, 4);

	s = ")()())()()(";
	test_func(s, 4);

    return 0;
}

