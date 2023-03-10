#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        unordered_map<int, int> need;
        for (auto ele : small) {
            need[ele]++;
        }
        int left = 0, right = 0, count = 0, len = big.size() + 1;
        vector<int> res;
        while (right < big.size()) {
            if (need.count(big[right])) {
                need[big[right]]--;
                if (need[big[right]] >= 0) {
                    count++;
                }
            }
            while (count == small.size()) {
                if (right - left + 1 < len) {
                    len = right - left + 1;
                    res = {left, right};
                }
                if (need.count(big[left])) {
                    need[big[left]]++;
                    if (need[big[left]] > 0) {
                        count--;
                    }
                }
                left++;
            }
            right++;
        }
        return res;
    }
}