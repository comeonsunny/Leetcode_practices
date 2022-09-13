// 459 repeated substring pattern
/*
    Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
    Example 1:
    Input: s = "abab"
    Output: true
    Explanation: It is the substring "ab" twice.
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        // brute force
        for (int i = 1; i <= n / 2; ++i) {
            // get the substring
            string sub = s.substr(0, i);
            // check if it is repeated
            int j = i;
            while (j + i <= n) {
                if (s.substr(j, i) != sub) {
                    break;
                }
                j += i;
            }
            if (j == n) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    Solution sol;
    string s = "abab";
    cout << sol.repeatedSubstringPattern(s) << endl;
    return 0;
}