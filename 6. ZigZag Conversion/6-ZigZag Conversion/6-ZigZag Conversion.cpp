// 6-ZigZag Conversion.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		string ret;

		if (numRows <= 1) {
			return s;	
		}

		for (int i = 0; i < numRows; ++i) {
			unsigned int start = i;
			while (start < s.size()) {
				ret.push_back(s[start]);
				start += (2 * numRows - 2);
				if (0 != i && numRows - 1 != i) {
					unsigned int extra = start - 2 * i;
					if (extra < s.size()) {
						ret.push_back(s[extra]);
					}
				}
			}
		}

		return ret;
	}
};

static void test_func(string str, int rows)
{
	Solution s;
	string ret;

	ret = s.convert(str, rows);
	cout << str << "->" << ret << endl;
}


int main()
{
	test_func("123456789", 1);
	test_func("123456789", 2);
	test_func("123456789", 3);
	test_func("123456789abcdefg", 4);

    return 0;
}

