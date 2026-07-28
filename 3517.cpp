/*
3517. Smallest Palindromic Rearrangement I


Description:

You are given a string s.

Return the palindromic of s.

 

Example 1:

Input: s = "z"

Output: "z"

Explanation:

A string of only one character is already the lexicographically smallest palindrome.

Example 2:

Input: s = "babab"

Output: "abbba"

Explanation:

Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.

Example 3:

Input: s = "daccad"

Output: "acddca"

Explanation:

Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.

 

Constraints:

    1 <= s.length <= 105
    s consists of lowercase English letters.
    s is guaranteed to be palindromic.


*/

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size() / 2;
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a'] += 1;
        }
        string out;
        for (int i = 0; i < cnt.size(); i++) {
            for (int j = 0; j < cnt[i]; j++) {
                out.push_back('a' + i);
            }
        }
        if ((s.size() % 2) == 1) {
            out.push_back(s[n]);
        }
        for (int i = cnt.size() - 1; i >= 0; i--) {
            for (int j = 0; j < cnt[i]; j++) {
                out.push_back('a' + i);
            }
        }
        return out;
    }
};
