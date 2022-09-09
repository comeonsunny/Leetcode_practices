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
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > target && nums[i] > 0 && target > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            vector<vector<int>> _res = threeSum(nums, i + 1, (long)target - nums[i]);
            for (int j = 0; j < _res.size(); j++) {
               _res[j].insert(_res[j].begin(), nums[i]);
                res.push_back(_res[j]);
            }
        }
        return res;
    }
private:
    vector<vector<int>> threeSum(vector<int>& nums, int start, long target) {
        vector<vector<int>> res;
        for (int i = start; i < nums.size(); i++) {
            if (nums[i] > target && nums[i] > 0 && target > 0) {
                break;
            }
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            vector<vector<int>> _res = twoSum(nums, i + 1, (long)target - nums[i]);
            for (int j = 0; j < _res.size(); j++) {
                _res[j].insert(_res[j].begin(), nums[i]);
                res.push_back(_res[j]);
            }
        }
        return res;
    }
    vector<vector<int>> twoSum(vector<int>& nums, int start, long target) {
        vector<vector<int>> res;
        int left = start;
        int right = nums.size() - 1;
        while (left < right) {
            long sum = (long)nums[left] + nums[right];
            if (sum == target) {
                res.push_back({nums[left], nums[right]});
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
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