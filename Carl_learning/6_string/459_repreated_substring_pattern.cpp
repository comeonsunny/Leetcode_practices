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
        // shift match
        string ss = s + s;
        ss = ss.substr(1, 2 * n - 2);
        return ss.find(s) != string::npos;
    }
};
int main() {
    Solution sol;
    string s = "abab";
    cout << sol.repeatedSubstringPattern(s) << endl;
    return 0;
} 