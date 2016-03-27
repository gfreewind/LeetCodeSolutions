// 22. Generate Parentheses.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	void compose_str(int left, int right, int max,
		string &str, vector<string> &ret)
	{
		if (left == max) {
			int cur_len = str.size();
			str.append(max - right, ')');
			ret.push_back(str);
			str.erase(cur_len, max - right);
			return;
		}

		str.push_back('(');
		compose_str(left + 1, right, max, str, ret);
		str.pop_back();

		if (right < left) {
			str.push_back(')');
			compose_str(left, right + 1, max, str, ret);
			str.pop_back();
		}
	}

	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		string str;

		if (n <= 0) {
			return ret;
		}

		compose_str(0, 0, n, str, ret);

		return ret;

	}
};

static void test_func(int n)
{
	Solution s;
	vector<string> ret = s.generateParenthesis(n);
	cout << n << " parentthese: ";
	for (auto it = ret.begin(); it != ret.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test_func(-1);
	test_func(0);
	test_func(1);
	test_func(2);
	test_func(3);
	test_func(4);

    return 0;
}

