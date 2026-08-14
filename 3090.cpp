/*
3090. Maximum Length Substring With Two Occurrences


Description:

Given a string s, return the maximum length of a  such that it contains at most two occurrences of each character.

 

Example 1:

Input: s = "bcbbbcba"

Output: 4

Explanation:
The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".

Example 2:

Input: s = "aaaa"

Output: 2

Explanation:
The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".

 

Constraints:

    2 <= s.length <= 100
    s consists only of lowercase English letters.


*/

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int start = 0;
        vector<int> occurs(26, 0);
        occurs[s[0] - 'a'] = 1;
        int out = 1;
        for (int i = 1; i < s.size(); i++) {
            while (occurs[s[i] - 'a'] == 2) {
                occurs[s[start] - 'a'] -= 1;
                start++;
            }
            occurs[s[i] - 'a'] += 1;
            out = max(out, i - start + 1);
        }
        return out;
    }
};
