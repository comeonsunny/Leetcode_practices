// 1047 Remove All Adjacent Duplicates In String
/*
    You are given a string s consisting of lowercase English letters. 
    A duplicate removal consists of choosing two adjacent and equal letters and removing them.
    We repeatedly make duplicate removals on s until we no longer can.
    Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
*/
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (auto c : s) {
            if (st.empty() || st.top() != c) {
                st.push(c);
            } else {
                st.pop();
            }
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main()
{
    Solution sol;
    string s = "abbaca";
    cout << sol.removeDuplicates(s) << endl;
    return 0;
}