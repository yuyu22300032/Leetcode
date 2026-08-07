/*
3348. Smallest Divisible Digit Product II


Description:

You are given a string num which represents a positive integer, and an integer t.

A number is called zero-free if none of its digits are 0.

Return a string representing the smallest zero-free number greater than or equal to num such that the product of its digits is divisible by t. If no such number exists, return "-1".

 

Example 1:

Input: num = "1234", t = 256

Output: "1488"

Explanation:

The smallest zero-free number that is greater than 1234 and has the product of its digits divisible by 256 is 1488, with the product of its digits equal to 256.

Example 2:

Input: num = "12355", t = 50

Output: "12355"

Explanation:

12355 is already zero-free and has the product of its digits divisible by 50, with the product of its digits equal to 150.

Example 3:

Input: num = "11111", t = 26

Output: "-1"

Explanation:

No number greater than 11111 has the product of its digits divisible by 26.

 

Constraints:

    2 <= num.length <= 2 * 105
    num consists only of digits in the range ['0', '9'].
    num does not contain leading zeros.
    1 <= t <= 1014


*/

class Solution {
public:
    string smallestNumber(string num, long long t) {
        vector<int> prime = {2, 3, 5, 7};
        vector<int> cnts(prime.size(), 0);
        {
            long long cur = t;
            for (int i = 0; i < prime.size(); i++) {
                while (cur % prime[i] == 0) {
                    cnts[i] += 1;
                    cur = cur / prime[i];
                }
            }
            if (cur > 1) {
                return "-1";
            }
        }
        vector<long long> rem(num.size() + 1);
        rem[0] = t;
        int pos = num.size() - 1;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] == '0') {
                pos = i;
                break;
            }
            rem[i + 1] = rem[i] / gcd(rem[i], num[i] - '0');
        }
        if (rem.back() == 1) {
            return num;
        }

        {
            string out = num;
            for (int i = pos; i >= 0; i--) {
                while (++out[i] <= '9') {
                    long long cur = rem[i] / gcd(rem[i], out[i] - '0');
                    int k = 9;
                    for (int j = num.size() - 1; j > i; j--) {
                        while (cur % k) {
                            k--;
                        }
                        cur /= k;
                        out[j] = '0' + k;
                    }
                    if (cur == 1) {
                        return out;
                    }
                }
            }
        }
        
        string rev;
        while (cnts[1] >= 2) {
            rev += '9';
            cnts[1] -= 2;
        }
        while (cnts[0] >= 3) {
            rev += '8';
            cnts[0] -= 3;
        }
        while (cnts[3] >= 1) {
            rev += '7';
            cnts[3] -= 1;
        }
        while (cnts[0] >= 1 && cnts[1] >= 1) {
            rev += '6';
            cnts[0] -= 1;
            cnts[1] -= 1;
        }
        while (cnts[2] >= 1) {
            rev += '5';
            cnts[2] -= 1;
        }
        while (cnts[0] >= 2) {
            rev += '4';
            cnts[0] -= 2;
        }
        while (cnts[1] >= 1) {
            rev += '3';
            cnts[1] -= 1;
        }
        while (cnts[0] >= 1) {
            rev += '2';
            cnts[0] -= 1;
        }
        int count = num.size() + 1 - rev.size();
        rev += string(max(count, 0), '1');
        string out;
        for (int i = rev.size() - 1; i >= 0; i--) {
            out += rev[i];
        }
        return out;
    }
};
