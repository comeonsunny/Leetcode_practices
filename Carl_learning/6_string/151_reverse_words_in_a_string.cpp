// 151 Reverse Words in a String
/*
    Given an input string, reverse the order of the words.
    A word is defined as a sequence of non-space characters.
    The words in s will be separated by at least one space.
    Return a string of the words in reverse order concatenated by a single space.
    Note that s may contain leading or trailing spaces or multiple spaces between two words.
    The returned string should only have a single space separating the words.
    Do not include any extra spaces.
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        // remove redundant spaces
        int slow = 0;
        for (int fast = 0; fast < s.size(); ++fast) {
            if (s[fast] != ' ') {
                if (slow != 0) {
                    s[slow++] = ' ';
                }
                while (fast < s.size() && s[fast] != ' ') {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
        // reverse the whole string
        reverse(s.begin(), s.end());
        // reverse each word
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};
int main() {
    Solution sol;
    string s = "the sky is blue";
    cout << sol.reverseWords(s) << endl;
    return 0;
}