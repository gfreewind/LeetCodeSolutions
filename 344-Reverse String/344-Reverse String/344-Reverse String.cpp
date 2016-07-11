// 344-Reverse String.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
	string reverseString(string s) {
		if (s.length() == 0) {
			return s;
		}

		auto it = s.begin();

		for (unsigned int i = 0; i < s.length() / 2; ++i) {
			swap(it[i], it[s.length() - i -1]);
		}

		return s;
	}
};

void test_func(string s, string expect)
{
	Solution sl;
	string orig = s;
	string ret = sl.reverseString(s);

	if (ret == expect) {
		cout << orig << " right Answer: " << ret << endl;
	}
	else {
		cout << orig << " wrong Answer: " << ret << endl;
	}
}

int main()
{
	string s;

	s = "";
	test_func(s, "");

	s = "a";
	test_func(s, "a");

	s = "ab";
	test_func(s, "ba");

	s = "abc";
	test_func(s, "cba");

	s = "abcd";
	test_func(s, "dcba");
    return 0;
}

