/*
 * [202] Happy Number
 *
 * https://leetcode.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (43.10%)
 * Total Accepted:    191.6K
 * Total Submissions: 444.6K
 * Testcase Example:  '19'
 *
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with
 * any positive integer, replace the number by the sum of the squares of its
 * digits, and repeat the process until the number equals 1 (where it will
 * stay), or it loops endlessly in a cycle which does not include 1. Those
 * numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 
 */
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while (n != 1) {
            if (visited.find(n) != visited.end()) {
                return false;
            }
            visited.insert(n);
            int s = 0;
            while (n > 0) {
                int d = n % 10;
                s += d * d;
                n /= 10;
            }
            n = s;
        }
        return true;
    }
};

