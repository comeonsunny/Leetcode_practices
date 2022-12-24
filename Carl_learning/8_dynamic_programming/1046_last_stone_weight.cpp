// 1046. Last Stone Weight
/* 
You are given an array of integers stones where stones[i] is the weight of the i-th stone.
We are playing a game with the stones. On each turn, we choose the heaviest two stones 
and smash them together. Suppose the heaviest two stones have weights x and y with x <= y.
The result of this smash is:
    If x == y, both stones are destroyed, and
    If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y-x.
At the end of the game, there is at most one stone left.
Return the weight of the last remaining stone. If there are no stones left, return 0.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto stone : stones) {
            pq.push(stone);
        }
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x - y) {
                pq.push(x - y);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
int main() 
{
    cout << "1046. Last Stone Weight" << endl;
    Solution sol;
    vector<int> stones = {2,7,4,1,8,1};
    cout << "The stones are: ";
    for (auto stone : stones) {
        cout << stone << " ";
    }
    cout << "The last stone weight is: " << sol.lastStoneWeight(stones) << endl;
    return 0;
}