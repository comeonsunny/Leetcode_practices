// 150 evaluate reverse polish notation
/*
    Evaluate the value of an arithmetic expression in Reverse Polish Notation.
    Valid operator are +, -, *, /. Each operand may be an integer or another expression.
    Note that division between two integers should truncate toward zero.
    It is guaranteed that the given RPN expression is always valid. 
    That means the expression would always evaluate to a result, 
    and there will not be any division by zero operation.
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                switch (token[0]) {
                    case '+':
                        st.push(num2 + num1);
                        break;
                    case '-':
                        st.push(num2 - num1);
                        break;
                    case '*':
                        st.push(num2 * num1);
                        break;
                    case '/':
                        st.push(num2 / num1);
                        break;
                }
            } else {
                // cout << stoi(token) << endl;
                st.push(stoi(token));
            }
        }
        int res = st.top();
        st.pop();
        return res;
    }
};
int main() 
{
    Solution sol;
    vector<string> tokens = {"2", "1", "+", "13", "*"};
    cout << sol.evalRPN(tokens) << endl;
    return 0;
}