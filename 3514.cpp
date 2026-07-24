/*
3514. Number of Unique XOR Triplets II


Description:

You are given an integer array nums.

A XOR triplet is defined as the XOR of three elements nums[i] XOR nums[j] XOR nums[k] where i <= j <= k.

Return the number of unique XOR triplet values from all possible triplets (i, j, k).

 

Example 1:

Input: nums = [1,3]

Output: 2

Explanation:

The possible XOR triplet values are:

    (0, 0, 0) → 1 XOR 1 XOR 1 = 1
    (0, 0, 1) → 1 XOR 1 XOR 3 = 3
    (0, 1, 1) → 1 XOR 3 XOR 3 = 1
    (1, 1, 1) → 3 XOR 3 XOR 3 = 3

The unique XOR values are {1, 3}. Thus, the output is 2.

Example 2:

Input: nums = [6,7,8,9]

Output: 4

Explanation:

The possible XOR triplet values are {6, 7, 8, 9}. Thus, the output is 4.

 

Constraints:

    1 <= nums.length <= 1500
    1 <= nums[i] <= 1500


*/

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> pair_xors;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                pair_xors.insert(nums[i] ^ nums[j]);
            }
        }
        unordered_set<int> xors;
        for (unordered_set<int>::iterator it = pair_xors.begin(); it != pair_xors.end(); it++) {
            for (int i = 0; i < nums.size(); i++) {
                xors.insert(*it ^ nums[i]);
            }
        }
        return xors.size();
    }
};
