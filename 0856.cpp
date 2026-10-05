/*
856. Score of Parentheses


Description:

Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

    "()" has score 1.
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.

 

Example 1:

Input: s = "()"
Output: 1

Example 2:

Input: s = "(())"
Output: 2

Example 3:

Input: s = "()()"
Output: 2

 

Constraints:

    2 <= s.length <= 50
    s consists of only '(' and ')'.
    s is a balanced parentheses string.


*/

class Solution {
public:
    int scoreOfParentheses(string s) {
        int out = 0;
        int layer = 1;
        int idx = 0;
        while (idx < s.size()) {
            if (s[idx] == '(') {
                if (s[idx + 1] == ')') {
                    out += layer;
                    idx++;
                } else {
                    layer *= 2;
                }
            } else {
                layer /= 2;
            }
            idx++;
        }
        return out;
    }
};
