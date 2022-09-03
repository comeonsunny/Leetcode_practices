// 454 4sum II
/*
    Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l)
    such that:
        1. 0 <= i, j, k, l < n
        2. nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt = 0;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                hash[nums1[i] + nums2[j]]++;
            }
        }
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                if (hash.count(-(nums3[i] + nums4[j]))) {
                    cnt += hash[-(nums3[i] + nums4[j])]; 
                }
            }
        }
        return cnt;
    }
};
int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};
    cout << sol.fourSumCount(nums1, nums2, nums3, nums4) << endl;
    return 0;
}