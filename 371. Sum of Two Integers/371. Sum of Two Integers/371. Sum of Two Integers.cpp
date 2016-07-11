// 371. Sum of Two Integers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostrea>

class Solution {
public:
	int getSum(int a, int b) {

		while (b) {
			int c = a^b;
			int d = (a&b) << 1;
			a = c;
			b = d;
		}

		return a;
	}
};


int main()
{
    return 0;
}

