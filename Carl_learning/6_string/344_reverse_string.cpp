// 344 Reverse String
/*
    Write a function that reverses a string. The input string is given as an array of characters s.
    You must do this by modifying the input array in-place with O(1) extra memory.
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }
};
int main() {
    Solution sol;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(s);
    for (auto c : s) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}