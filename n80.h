//
// Created by 蒋子涵 on 2023/9/9.
//

#ifndef LEETCODE2023_N80_H
#define LEETCODE2023_N80_H
#include "global.h"

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int pre = nums[0];
		int pos = 1;
		int count = 0;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] != pre) {
				count = 0;
				swap(nums[i], nums[pos]);
				pre = nums[pos];
				pos++;
			}
			else {
				count++;
				if (count < 2) {
					swap(nums[i], nums[pos]);
					pre = nums[pos];
					pos++;
				}
			}
		}
		return pos;
	}
};
#endif //LEETCODE2023_N80_H
