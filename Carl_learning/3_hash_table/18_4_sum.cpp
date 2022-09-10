// 18 4Sum
/**
 * Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
 * 0 <= a, b, c, d < n
 * a, b, c, and d are distinct.
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 * You may return the answer in any order.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            long _target = target - nums[i];
            vector<vector<int>> _res = threeSum(nums, _target, i);
            for (auto v : _res) {
                v.insert(v.begin(), nums[i]);
                res.push_back(v);
            }
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) ++i;
        }
    }
private:
    vector<vector<int>> threeSum(vector<int>& nums, int target, int index) {
        vector<vector<int>> res;
        for (int i = index + 1; i < nums.size(); ++i) {
            long _target = target - nums[i];
            if (i > index + 1 && nums[i] == nums[i - 1]) continue;
            vector<vector<int>> _res = twoSum(nums, _target, i);
            for (auto v : _res) {
                v.insert(v.begin(), nums[i]);
                res.push_back(v);
            }
        }
        return res;
    }
    vector<vector<int>> twoSum(vector<int>& nums, int target, int index) {
        vector<vector<int>> res;
        int left = index + 1;
        int right = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                res.push_back({nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;
                ++left;
                --right;
            } else if (nums[left] + nums[right] < target) {
                ++left;
            } else {
                --right;
            }
        }
        return res;
    }
};
int main() 
{
    Solution s;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> res = s.fourSum(nums, 0);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}