/*
 * [929] Groups of Special-Equivalent Strings
 *
 * https://leetcode.com/problems/groups-of-special-equivalent-strings/description/
 *
 * algorithms
 * Easy (60.73%)
 * Total Accepted:    6.7K
 * Total Submissions: 11.1K
 * Testcase Example:  '["a","b","c","a","c","c"]'
 *
 * You are given an array A of strings.
 * 
 * Two strings S and T are special-equivalent if after any number of moves, S
 * == T.
 * 
 * A move consists of choosing two indices i and j with i % 2 == j % 2, and
 * swapping S[i] with S[j].
 * 
 * Now, a group of special-equivalent strings from A is a non-empty subset S of
 * A such that any string not in S is not special-equivalent with any string in
 * S.
 * 
 * Return the number of groups of special-equivalent strings from A.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["a","b","c","a","c","c"]
 * Output: 3
 * Explanation: 3 groups ["a","a"], ["b"], ["c","c","c"]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["aa","bb","ab","ba"]
 * Output: 4
 * Explanation: 4 groups ["aa"], ["bb"], ["ab"], ["ba"]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: ["abc","acb","bac","bca","cab","cba"]
 * Output: 3
 * Explanation: 3 groups ["abc","cba"], ["acb","bca"], ["bac","cab"]
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: ["abcd","cdab","adcb","cbad"]
 * Output: 1
 * Explanation: 1 group ["abcd","cdab","adcb","cbad"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 1000
 * 1 <= A[i].length <= 20
 * All A[i] have the same length.
 * All A[i] consist of only lowercase letters.
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> ss;
        for (string s : A) {
            ss.insert(sort1(s));
        }
        return ss.size();
    }

private:
    string sort1(string s) {
        string odd;
        string even;
        for (int i = 0; i < s.length(); i++) {
            if (i % 2 == 0) {
                odd.append(1, s[i]);
            } else {
                even.append(1, s[i]);
            }
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        return odd + even;
    }
};

