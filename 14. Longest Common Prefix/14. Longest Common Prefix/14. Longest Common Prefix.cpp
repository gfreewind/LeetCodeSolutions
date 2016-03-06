// 14. Longest Common Prefix.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool str_len_comp(string str1, string str2)
{
	return (str1.size() < str2.size());
}

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) {
			return "";
		}
		else if (strs.size() == 1) {
			return strs[0];
		}

		sort(strs.begin(), strs.end(), str_len_comp);

		unsigned int i;
		for (i = 0; i < strs[0].size(); ++i) {
			for (unsigned int j = 1; j < strs.size(); ++j) {
				if (strs[j][i] != strs[0][i]) {
					goto exit;
				}
			}
		}

exit:
		return strs[0].substr(0, i);

	}
};

static void test_func(vector<string> &strs)
{
	Solution s;
	string ret = s.longestCommonPrefix(strs);

	cout << "Result is " << ret << endl;
}

int main()
{
	vector<string> v = { "abc", "abcdef", "ab" };
	test_func(v);

	v = {};
	test_func(v);

	v = { "abc" };
	test_func(v);

	v = { "abc", "a" };
	test_func(v);

	v = { "abc", "ab", "cdef"};
	test_func(v);

    return 0;
}

