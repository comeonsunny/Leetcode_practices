// 242 Valid Anagram
/*
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically 
    using all the original letters exactly once.
*/
#include <iostream>
#include <string>
using namespace std;
// Solution 1: sort the two strings and compare them
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         return s == t;
//     }
// };
// Solution 2: use a hash table to count the frequency of each character in s (hash table : array, set, and map)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int hash[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++;
            hash[t[i] - 'a']--;
        }
        // check if all the elements in hash are 0
        for (int i = 0; i < 26; i++) {
            if (hash[i]) return false;
        }
        return true;
    }
};
int main() 
{
    Solution s;
    bool res = s.isAnagram("anagram", "nagaram");
    string ans = res ? "true" : "false";
    cout << ans << endl;
    return 0;
}