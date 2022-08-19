// Number of students doing homework ast a given time
/* 
Given two integer arrays startTime and endTime and given an integer queryTime.
The ith student started doing their homework at the time startTime[i] and finished it at time endTime[i].
Return the number of students doing their homework at time queryTime.
More formally, return the number of students where queryTime lays in the interval [startTime[i], endTime[i]] inclusive.
 */
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int res = 0;
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            if (queryTime >= startTime[i] && queryTime <= endTime[i]) {
                res++;
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> startTime = {1,2,3};
    vector<int> endTime = {3,2,7};
    int queryTime = 4;
    cout << s.busyStudent(startTime, endTime, queryTime) << endl;
    return 0;
}