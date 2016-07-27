// 326. Power of Three.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n < 0) {
			return false;
		}

		if (n == 1) {
			return true;
		} else if (n < 3) {
			return false;
		}

		while (n != 1) {
			if (n % 3 != 0) {
				return false;
			}
			n /= 3;
		}

		return true;

	}
};

int main()
{
	Solution s;
	int i = 27;

	bool ret = s.isPowerOfThree(i);

    return 0;
}

