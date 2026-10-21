/*
3863. Minimum Operations to Sort a String


Description:

You are given a string s consisting of lowercase English letters.

In one operation, you can select any substring of s that is not the entire string and sort it in non-descending alphabetical order.

Return the minimum number of operations required to make s sorted in non-descending order. If it is not possible, return -1.

 

Example 1:

Input: s = "dog"

Output: 1

Explanation:​​​​​​​

    Sort substring "og" to "go".
    Now, s = "dgo", which is sorted in ascending order. Thus, the answer is 1.

Example 2:

Input: s = "card"

Output: 2

Explanation:

    Sort substring "car" to "acr", so s = "acrd".
    Sort substring "rd" to "dr", making s = "acdr", which is sorted in ascending order. Thus, the answer is 2.

Example 3:

Input: s = "gf"

Output: -1

Explanation:

    It is impossible to sort s under the given constraints. Thus, the answer is -1.

 

Constraints:

    1 <= s.length <= 105
    s consists of only lowercase English letters.


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
