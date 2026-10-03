/*
32. Longest Valid Parentheses


Description:

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:

Input: s = ""
Output: 0

 

Constraints:

    0 <= s.length <= 3 * 104
    s[i] is '(', or ')'.


*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int out = 0;
        stack<int> opens;
        opens.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                opens.push(i);
            } else {
                opens.pop();
                if (opens.empty()) {
                    opens.push(i);
                } else {
                    out = max(out, i - opens.top());
                }
            }
        }
        return out;
    }
};
