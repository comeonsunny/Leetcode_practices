//349 Intersection of Two Arrays
/*
    Given two integer arrays nums1 and nums2, return an array of their intersection.
    Each element in the result must be unique and you may reurn the result in any order.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// class Solution {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//         unordered_set<int> s1(nums1.begin(), nums1.end());
//         unordered_set<int> s2(nums2.begin(), nums2.end());
//         vector<int> res;
//         for (auto i : s1) {
//             if (s2.find(i) != s2.end()) {
//                 res.push_back(i);
//             }
//         }
//         return res;
//     }
// };
//solution 2 leverage the array to find the intersection of two arrays
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int hash[1000] = {0};
        for (auto num : nums1) {
            hash[num]++;
        }
        for (auto num : nums2) {
            if (hash[num]) {
                res.push_back(num);
                hash[num] = 0;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> res = s.intersection(nums1, nums2);
    cout << "res: ";
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}