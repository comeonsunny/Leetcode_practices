#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> count, freq;
        int res = 0;
        int maxFreq = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count[nums[i]] > 0) {
                freq[count[nums[i]]]--;
            }
            count[nums[i]]++;
            freq[count[nums[i]]]++;
            maxFreq = max(maxFreq, count[nums[i]]);
            bool ok = maxFreq == 1 || freq[maxFreq] == 1 && freq[maxFreq] * maxFreq + freq[maxFreq - 1] * (maxFreq - 1) == i + 1 ||
                      freq[1] == 1 && freq[maxFreq] * maxFreq + 1 == i + 1;
            if (ok) {
                res = max(res, i + 1);
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    // [1,1,1,2,2,2,3,3,3,4,4,4,5]
    vector<int> nums = {1,1,1,2,2,2,3,3,3,4,4,4,5};
    cout << s.maxEqualFreq(nums) << endl;
    return 0;
}