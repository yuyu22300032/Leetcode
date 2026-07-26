/*
628. Maximum Product of Three Numbers


Description:

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

 

Example 1:

Input: nums = [1,2,3]
Output: 6

Example 2:

Input: nums = [1,2,3,4]
Output: 24

Example 3:

Input: nums = [-1,-2,-3]
Output: -6

 

Constraints:

    3 <= nums.length <= 104
    -1000 <= nums[i] <= 1000


*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        bool has_zero = false;
        int pos[3] = {0};
        int min_neg[2] = {0};
        int max_neg[3] = {INT_MIN, INT_MIN, INT_MIN};
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                has_zero = true;
                continue;
            }
            if (nums[i] > pos[2]) {
                if (nums[i] > pos[1]) {
                    pos[2] = pos[1];
                    if (nums[i] > pos[0]) {
                        pos[1] = pos[0];
                        pos[0] = nums[i];
                    } else {
                        pos[1]  = nums[i];
                    }
                } else {
                    pos[2]  = nums[i];
                }
                continue;
            }
            if (nums[i] < min_neg[1]) {
                if (nums[i] < min_neg[0]) {
                    min_neg[1] = min_neg[0];
                    min_neg[0] = nums[i];
                } else {
                    min_neg[1] = nums[i];
                }
            }
            if (nums[i] < 0) {
                if (nums[i] > max_neg[2]) {
                    if (nums[i] > max_neg[1]) {
                        max_neg[2] = max_neg[1];
                        if (nums[i] > max_neg[0]) {
                            max_neg[1] = max_neg[0];
                            max_neg[0] = nums[i];
                        } else {
                            max_neg[1]  = nums[i];
                        }
                    } else {
                        max_neg[2]  = nums[i];
                    }
                }
            }
        }
        int out = INT_MIN;
        if (pos[2] > 0) {
            return max(pos[0] * pos[1] * pos[2], pos[0] * min_neg[0] * min_neg[1]);
        }
        if (pos[0] > 0 && min_neg[1] < 0) {
            return pos[0] * min_neg[0] * min_neg[1];
        }
        if (has_zero) {
            return 0;
        }
        if (pos[1] > 0) {
            return max(pos[0] * pos[1] * max_neg[0], max_neg[0] * max_neg[1] * max_neg[2]);
        }
        return max_neg[0] * max_neg[1] * max_neg[2];
    }
};
