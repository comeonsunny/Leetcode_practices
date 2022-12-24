//1049 Last stone Weight II
/*
 You are given an array of integers stones where stones[i] is the weight of 
    the ith stone.
We are playing a game with the stones. On each turn, we choose any tow stones and 
smash them together. Suppose the stones have weights x and y with x <= y. The result of this smash is:
    If x == y, both stones are destroyed, and
    If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y-x.
At the end of the game, there is at most one stone left.
Return the smallest possible weight of the left stone.
If there are no stones left, return 0.
*/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int n = stones.size();
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - 2 * dp[target];
    }
};
int main()
{
    vector<int> stones = { 2,7,4,1,8,1 };
    Solution sol;
    int res = sol.lastStoneWeightII(stones);
    cout << res << endl;
    return 0;
}