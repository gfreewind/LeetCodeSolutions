// 28. Implement strStr().cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		return haystack.find(needle);
	}
};

int main()
{
    return 0;
}

