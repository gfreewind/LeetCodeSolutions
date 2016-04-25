// 32. Longest Valid Parentheses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.size() == 0) {
			return 0;
		}

		int max_len = 0;
		for (uint32_t i = 1; i < s.size(); ++i) {
			if (')' == s[i]) {
				int sum = 1;
				int cnt = 0;
				for (int j = i - 1; j >= 0; --j) {
					if ('(' == s[j]) {
						sum--;
						if (sum >= 0) {
							cnt++;
						}
						else {
							break;
						}
					}
					else {
						sum++;
					}
				}

				if (sum > 0) {
					// Invalid parenthese, need to rollback
					for (int j = 0; j <= i - 1; ++j) {
						if (')' == s[j]) {
							--sum;
						}
						else if ('(' == s[j]) {
							--cnt;
							++sum;
						}
						if (0 == sum) {
							break;
						}
					}
				}

				if (cnt * 2 > max_len) {
					max_len = cnt * 2;
				}
			}
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

