// 292 Nim Game.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Solution {
public:
	bool canWinNim(int n) {
		return n%4;
	}
};

void test_func(int n, bool expect)
{
	Solution s;
	bool ret = s.canWinNim(n);

	cout << "Heap " << n << "'s winner is " << ret;
	if (ret == expect) {
		cout << ", good" << endl;
	}
	else {
		cout << ", wrong!!!" << endl;
	}
}

int main()
{
	test_func(0, true);
	test_func(1, true);
	test_func(2, true);
	test_func(3, true);
	test_func(4, false);
	
    return 0;
}

