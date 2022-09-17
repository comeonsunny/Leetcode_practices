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
        // kmp algorithm
        vector<int> next(n, 0);
        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
        return next[n - 1] && n % (n - next[n - 1]) == 0;
    }
};
int main() {
    Solution sol;
    string s = "abab";
    cout << sol.repeatedSubstringPattern(s) << endl;
    return 0;
} 