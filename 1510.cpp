/*
1510. Stone Game IV


Description:

Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.

 

Example 1:

Input: n = 1
Output: true
Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.

Example 2:

Input: n = 2
Output: false
Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).

Example 3:

Input: n = 4
Output: true
Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).

 

Constraints:

    1 <= n <= 105


*/

class Solution {
    bool winGame(int n, unordered_map<int, bool>& cache) {
        bool can_win = false;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            if (sq > n) {
                break;
            }
            if (sq == n) {
                cache[sq] = true;
                can_win = true;
                break;
            }
            int left = n - sq;
            unordered_map<int, bool>::iterator it = cache.find(left);
            if (it != cache.end()) {
                if (it->second) {
                    can_win = true;
                }
                continue;
            }
            bool lost = winGame(left, cache);
            cache[left] = !lost;
            if (!lost) {
                can_win = true;
            }
        }
        return can_win;
    }
public:
    bool winnerSquareGame(int n) {
        unordered_map<int, bool> cache;
        return winGame(n, cache);
    }
};
