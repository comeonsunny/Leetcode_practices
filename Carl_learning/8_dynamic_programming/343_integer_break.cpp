/*
    343. Integer Break
    Given an integer n, break it into the sum of k positive integers, where k >=2,
    and maximize the product of those integers. Return the maximum product you can get.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 0;
        dp[2] = 1;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j < i / 2 + 1; ++j) {
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};
int main()
{
    Solution s;
    cout << s.integerBreak(10) << endl;
    return 0;
}