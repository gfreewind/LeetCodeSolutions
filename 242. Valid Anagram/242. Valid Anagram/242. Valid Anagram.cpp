// 242. Valid Anagram.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		vector<int> v1(26);
		vector<int> v2(26);

		if (s.size() != t.size()) {
			return false;
		}

		for (auto it = s.begin(); it != s.end(); ++it) {
			int index = *it - 'a';
			v1[index] += 1;
		}

		for (auto it = t.begin(); it != t.end(); ++it) {
			int index = *it - 'a';
			v2[index] += 1;
		}

		return (v1 == v2);

	}
};


int main()
{
    return 0;
}

