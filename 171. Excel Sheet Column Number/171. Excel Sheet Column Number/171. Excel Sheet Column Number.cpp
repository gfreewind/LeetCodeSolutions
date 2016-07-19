// 171. Excel Sheet Column Number.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int titleToNumber(string s) {
		int ret = 0;

		for (auto it = s.begin(); it != s.end(); ++it) {
			ret *= 26;
			ret += (*it - 'A' + 1);
		}

		return ret;
	}
};

int main()
{
	string ss = "A";
	Solution s;
	int ret = s.titleToNumber(ss);
	cout << ss << ": " << ret << endl;
	
	ss = "Z";
	ret = s.titleToNumber(ss);
	cout << ss << ": " << ret << endl;

	ss = "AZ";
	ret = s.titleToNumber(ss);
	cout << ss << ": " << ret << endl;

	ss = "ZZ";
	ret = s.titleToNumber(ss);
	cout << ss << ": " << ret << endl;

	return 0;
}

