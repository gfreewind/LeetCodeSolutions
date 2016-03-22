// 20. Valid Parentheses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> braces;

		for (unsigned int i = 0; i < s.size(); ++i) {
			if ('(' == s[i] || '{' == s[i] || '[' == s[i]) {
				braces.push(s[i]);
			}
			else if (')' == s[i]) {
				if (braces.size() == 0) {
					return false;
				}

				char last = braces.top();
				if (last != '(') {
					return false;
				}
				braces.pop();
			}
			else if ('}' == s[i]) {
				if (braces.size() == 0) {
					return false;
				}
				char last = braces.top();
				if (last != '{') {
					return false;
				}
				braces.pop();
			}
			else if (']' == s[i]) {
				if (braces.size() == 0) {
					return false;
				}
				char last = braces.top();
				if (last != '[') {
					return false;
				}
				braces.pop();
			}
		}

		return (braces.size() == 0);
	}
};

static void test_func(string str, bool expect)
{
	Solution s;
	bool ret = s.isValid(str);

	cout << str << " is " << ret;
	if (expect) {
		if (!ret) {
			cout << ", not expected!!!";
		}
	}
	else {
		if (ret) {
			cout << ", not expected!!!";
		}
	}
	cout << endl;
}

int main()
{
	string s;

	test_func(s, true);
	s = "abc";
	test_func(s, true);
	s = "a[]c";
	test_func(s, true);
	s = "a[{(dfdafdf)}]";
	test_func(s, true);
	s = "a[[[]]adfd}";
	test_func(s, false);

	s = "]";
	test_func(s, false);

    return 0;
}

