/*
678. Valid Parenthesis String


Description:

Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "(*)"
Output: true

Example 3:

Input: s = "(*))"
Output: true

Example 4:

Input: s = "("
Output: false

 

Constraints:

    1 <= s.length <= 100
    s[i] is '(', ')' or '*'.


*/

class Solution {
public:
    bool checkValidString(string s) {
        int open_max = 0;
        int open_min = 0;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '(': {
                    open_max++;
                    open_min++;
                    break;
                }
                case '*': {
                    open_max++;
                    if (open_min > 0) {
                        open_min--;
                    }
                    break;
                }
                case ')': {
                    if (open_max == 0) {
                        return false;
                    }
                    open_max--;
                    if (open_min > 0) {
                        open_min--;
                    }
                    break;
                }
            }
        }
        return open_min == 0;
    }
};
