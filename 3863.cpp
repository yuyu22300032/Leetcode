/*
1. Two Sum


Description:

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

 

Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.

 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?


*/

class Solution {
public:
    int minOperations(string s) {
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        if (s == sorted) {
            return 0;
        }
        if (s.size() == 2) {
            return -1;
        }
        if (s.front() == sorted.front() || s.back() == sorted.back()) {
            return 1;
        }
        int min_c = 0;
        int max_c = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] < s[min_c]) {
                min_c = i;
            }
            if (s[i] >= s[max_c]) {
                max_c = i;
            }
        }
        if (min_c == s.size() - 1 && max_c == 0) {
            return 3;
        }
        return 2;
    }
};
