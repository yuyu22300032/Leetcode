/*
22. Generate Parentheses


Description:

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:

Input: n = 1
Output: ["()"]

 

Constraints:

    1 <= n <= 8


*/

class Solution {
    struct GenerateState {
        int opened;
        int paran;
        string str;

        GenerateState(int n)
        : opened(0)
        , paran(n)
        , str() { ; }
    };
public:
    vector<string> generateParenthesis(int n) {
        queue<GenerateState> generating;
        GenerateState base(n);
        generating.push(base);
        vector<string> out;
        while (!generating.empty()) {
            GenerateState cur = generating.front();
            generating.pop();
            if ((cur.opened == 0) && (cur.paran == 0)) {
                out.push_back(cur.str);
                continue;
            }
            if (cur.opened > 0) {
                GenerateState next = cur;
                next.opened -= 1;
                next.str += ')';
                generating.push(next);
            }
            if (cur.paran > 0) {
                GenerateState next = cur;
                next.paran -= 1;
                next.opened += 1;
                next.str += '(';
                generating.push(next);
            }
        }
        return out;
    }
};
