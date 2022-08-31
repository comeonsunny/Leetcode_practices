// 567. permutation in string
/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is a substring of s2.
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int fast = 0, slow = 0;
        unordered_map<char, int> need, window;
        for (char c : s1) need[c]++;
        int valid = 0;
        while (fast < s2.size()) {
            char c = s2[fast];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) ++valid;
            }
            while (valid == need.size()) {
                if (fast - slow + 1 == s1.size()) return true;
                char d = s2[slow++];
                if (need.count(d)) {
                    if (window[d] == need[d]) --valid;
                    window[d]--;
                }
            }
            ++fast;
        }
        return false;
    }
};
int main()
{
    Solution s;
    bool flag = s.checkInclusion("ab", "eidbaooo");
    string result = flag ? "eibaooo contains ab" : "eibaooo does not contain ab";
    cout << result << endl;
    return 0;
}