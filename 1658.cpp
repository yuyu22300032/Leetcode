/*
1658. Minimum Operations to Reduce X to Zero


Description:

You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

 

Example 1:

Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1

Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.

 

Constraints:

    1 <= nums.length <= 105
    1 <= nums[i] <= 104
    1 <= x <= 109


*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int out = INT_MAX;
        int left = 0;
        int cur = 0;
        while (left < nums.size()) {
            cur += nums[left];
            left++;
            if (cur < x) {
                continue;
            }
            if (cur == x) {
                out = left;
            }
            break;
        }
        if (left == nums.size()) {
            return out == INT_MAX ? -1 : out;
        }
        int right = nums.size();
        while (left >= 0) {
            while (cur < x) {
                right--;
                cur += nums[right];
                if (cur == x) {
                    int count = left + nums.size() - right;
                    out = min(out, count);
                }
            }
            if (left == 0) {
                break;
            }
            left--;
            cur -= nums[left];
            if (cur == x) {
                int count = left + nums.size() - right;
                out = min(out, count);
            }
        }
        return out == INT_MAX ? -1 : out;
    }
};
