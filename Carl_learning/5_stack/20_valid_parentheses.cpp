// 20 valid parentheses
/*
    Given a string s containing just hte characters '(',')', '{', '}', '[' and ']', 
    determine if the input string is valid.
    An input string is valid if:
    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.
    3. Every close bracket has a corresponding open bracket of the same type.
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                if (stk.empty()) {
                    return false;
                }
                char top = stk.top();
                if (s[i] == ')' && top != '(') {
                    return false;
                }
                if (s[i] == ']' && top != '[') {
                    return false;
                }
                if (s[i] == '}' && top != '{') {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
int main()
{
    Solution sol;
    string s = "([)]";
    cout << sol.isValid(s) << endl;
    return 0;
}