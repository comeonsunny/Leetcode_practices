// 2076 Process Restricted Friend Requests
/*
    You are given an integer n indicating the number of people in a network. Each person is labeled from 0 to n-1.
    You are also given a 0-indexed 2D integer array restrictions, where restrictions[i] = [xi, yi] means that person 
    xi and person yi cannot become friends, either directly or indirectly through other people.
    Initially, no one is friends with each other. You are given a list of friend requests as  a 0-indexed 2D integer array requests,
    where requests[i] = [ui, vi] is a friend request between person uj and person vj.
    A friend request is successful if uj and vj  can be friends. Each friend request is processed in the given order (i.e., request[j] occurs
    before request[j+1]), and upon a successful request, person uj and person vj become direct friends for all future 
    friend requests.
    Return a boolean array result, where each result[j] is true if the jth frind request is successful or false if it is not.
    Note: If uj and vj are already direct friends, the request is still successful.
*/
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution {
private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
    void union_(vector<int>& parent, vector<int>& rank, int x, int y) {
        int root_x = find(parent, x);
        int root_y = find(parent, y);
        if (root_x == root_y) {
            return;
        }
        if (rank[root_x] < rank[root_y]) {
            parent[root_x] = root_y;
        } else if (rank[root_x] > rank[root_y]) {
            parent[root_y] = root_x;
        } else {
            parent[root_y] = root_x;
            rank[root_x] += 1;
        }
    }
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        vector<int> rank(n, 0);
        vector<bool> res;
        for (const auto& request : requests) {
            int x = find(parent, request[0]);
            int y = find(parent, request[1]);
            if (x == y) {
                res.push_back(true);
                continue;
            }
            bool flag = true;
            for (const auto& restriction : restrictions) {
                int u = restriction[0];
                int v = restriction[1];
                u = find(parent, u);
                v = find(parent, v);
                if ((u == x && v == y) || (u == y && v == x)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                union_(parent, rank, x, y);
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<vector<int>> restrictions = {{0,1},{1,2},{1,3},{2,3},{3,4}};
    vector<vector<int>> requests = {{0,1},{0,2},{1,2},{3,4},{4,5}};
    vector<bool> res = s.friendRequests(6, restrictions, requests);
    for (const auto& r : res) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}