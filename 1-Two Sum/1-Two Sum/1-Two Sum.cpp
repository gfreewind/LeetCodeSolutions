// 1-Two Sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
	class ValuePos{
	public:
		int value;
		int index;
	};
private:
	static bool ValuePosComp(ValuePos i, ValuePos j) {
		return (i.value < j.value);
	}

public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<ValuePos> v;

		for (auto it = nums.begin(); it != nums.end(); ++it) {
			ValuePos p;
			p.value = *it;
			p.index = it - nums.begin();
			v.push_back(p);
		}

		std::sort(v.begin(), v.end(), ValuePosComp);

		auto head = v.begin();
		auto tail = v.end() - 1;
		vector<int> result;
		int s;

		while (head < tail) {
			s = head->value + tail->value;
			if (s > target) {
				--tail;
			}
			else if (s < target) {
				++head;
			}
			else {
				result.push_back(head->index);
				result.push_back(tail->index);
				return result;
			}
		}

		return result;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 3, 2, 4 };
	vector<int> result = s.twoSum(nums, 6);

	for (auto it = result.begin(); it != result.end(); it++) {
		cout << *it << endl;
	}

    return 0;
}

