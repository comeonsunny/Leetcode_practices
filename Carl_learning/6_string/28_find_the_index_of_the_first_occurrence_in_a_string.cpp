// 28 find the index of the First Occurrence in a string
/*
    Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, 
    or -1 if needle is not part of haystack.

*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        // brute force algorithm
        // time complexity: O((n-m+1)*m)
        // space complexity: O(1)
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i < n - m + 1; i++) {
            int j = 0; 
            for (; j < m; j++) {
                if (haystack[i +j] != needle[j]) {
                    break;
                }
            }
            if (j == m) return i;
        }
        return -1;
    }
};
int main() {
    Solution s;
    string haystack = "hello";
    string needle = "ll";
    cout << s.strStr(haystack, needle) << endl;
    return 0;
}