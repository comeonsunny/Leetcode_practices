// 76 Minimum Window Substring
/*
    Given two strings s and t of lengths m and n respectively, return the minimum window substring of s
    such that every character in t (including duplicates) is included in the window.
    If there is no such substring, return the empty string.
    The testcases will be generated such that the answer is unique.
    A substring is a congiguous sequence of characters within a string.
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int fast = 0, slow = 0;
        unordered_map<char, int> need, window;
        int start = 0, min_len = INT_MAX; // log the potential minimum window substring
        int valid = 0; // the number of characters of t in the window
        for (auto c : t) need[c]++;
        while (fast < s.size()) {
            char c = s[fast];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) ++valid;
            }
            while (valid == need.size()) {
                if (fast - slow + 1 < min_len) {
                    min_len = fast- slow + 1;
                    start = slow;
                }
                char d = s[slow++];
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
            ++fast;
        }
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};
int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution sol;
    cout << sol.minWindow(s, t) << endl;
    return 0;
}