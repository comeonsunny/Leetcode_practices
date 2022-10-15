// 746. Min Cost Climbing Stairs
/*
    You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
    Once you pay the cost, you can either climb one or two steps.
    You can either start from the step with index 0, or the step with index 1.
    Return the minimum cost to reach the top of the floor. 
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i <= n; ++i) {
            dp[i] = min(dp[i-1], dp[i-2]) + (i == n ? 0 : cost[i]);
        }
        return dp[n];
    }
};
int main() {
    Solution sol;
    vector<int> cost = {10, 15, 20};
    cout << sol.minCostClimbingStairs(cost) << endl;
    return 0;
}