/*
2567. Minimum Score by Changing Two Elements


Description:

You are given an integer array nums.

    The low score of nums is the minimum absolute difference between any two integers.
    The high score of nums is the maximum absolute difference between any two integers.
    The score of nums is the sum of the high and low scores.

Return the minimum score after changing two elements of nums.

 

Example 1:

Input: nums = [1,4,7,8,5]

Output: 3

Explanation:

    Change nums[0] and nums[1] to be 6 so that nums becomes [6,6,7,8,5].
    The low score is the minimum absolute difference: |6 - 6| = 0.
    The high score is the maximum absolute difference: |8 - 5| = 3.
    The sum of high and low score is 3.

Example 2:

Input: nums = [1,4,3]

Output: 0

Explanation:

    Change nums[1] and nums[2] to 1 so that nums becomes [1,1,1].
    The sum of maximum absolute difference and minimum absolute difference is 0.

 

Constraints:

    3 <= nums.length <= 105
    1 <= nums[i] <= 109


*/

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        vector<int> min_vals(3, INT_MAX);
        vector<int> max_vals(3, INT_MIN);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < min_vals[2]) {
                if (nums[i] < min_vals[1]) {
                    if (nums[i] < min_vals[0]) {
                        min_vals[2] = min_vals[1];
                        min_vals[1] = min_vals[0];
                        min_vals[0] = nums[i];
                    } else {
                        min_vals[2] = min_vals[1];
                        min_vals[1] = nums[i];
                    }
                } else {
                    min_vals[2] = nums[i];
                }
            }
            if (nums[i] > max_vals[2]) {
                if (nums[i] > max_vals[1]) {
                    if (nums[i] > max_vals[0]) {
                        max_vals[2] = max_vals[1];
                        max_vals[1] = max_vals[0];
                        max_vals[0] = nums[i];
                    } else {
                        max_vals[2] = max_vals[1];
                        max_vals[1] = nums[i];
                    }
                } else {
                    max_vals[2] = nums[i];
                }
            }
        }

        int out = max_vals[1] - min_vals[1];
        out = min(out, max_vals[0] - min_vals[2]);
        out = min(out, max_vals[2] - min_vals[0]);
        return out;
    }
};

