// 541. Reverse String II
/*
    Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of  the string.
    If there are fewer than k characters left, reverse all of them.
    If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += 2 * k) {
            int l = i, r = min(i + k - 1, n - 1);
            reverse(s, l, r);
        }
        return s;
    }
private:
    void reverse(string& s, int l, int r) {
       int left = l, right = r;
       while (left < right) {
            swap(s[left++], s[right--]);
       }
    }
};
int main() {
    Solution sol;
    string s = "abcdefg";
    int k = 2;
    cout << sol.reverseStr(s, k) << endl;
    return 0;
}