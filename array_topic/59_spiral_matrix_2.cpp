// spiral matrix II
/*
    Given a positive integer n, generate a square matrix filled with elements from 1 to n*n in spiral order.
*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int rowStart = 0, colStart = 0;
        int layer = 0;
        int count = 1;
        int i, j;
        while (layer < n/2) { 
            // if n is odd, the last element needs special process
            i = rowStart;
            for (j = colStart; j < n - 1 - layer; ++j) {
                res[i][j] = count++;
            }
            for (; i < n - 1 - layer; ++i) {
                res[i][j] = count++;
            }
            for (; j > colStart; --j) {
                res[i][j] = count++;
            }
            for (; i > rowStart; --i) {
                res[i][j] = count++;
            }
            ++rowStart;
            ++colStart;
            ++layer;
        }
        if ( n % 2 ) {
            res[rowStart][colStart] = count;
        }
        return res;
    }
};
int main()
{
    Solution s;
    int n = 4;
    vector<vector<int>> res = s.generateMatrix(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}