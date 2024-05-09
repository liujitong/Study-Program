#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int dfs(vector<vector<vector<int>>>& memo, vector<vector<int>>& grid, int i,
            int j, int k) {
        int m = grid.size(), n = grid[0].size();
        // 越界处理
        if (i == m || j < 0 || j >= n || k < 0 || k >= n)
            return 0;
        int& res = memo[i][j][k];
        if (res != -1)
            return res;
        for (int j2 = j - 1; j2 <= j + 1; j2++) {
            for (int k2 = k - 1; k2 <= k + 1; k2++) {
                res = max(res, dfs(memo, grid, i + 1, j2, k2)); // 递归求解
            }
        }
        res += grid[i][j];
        if (k == j)
            return res;
        else {
            res += grid[i][k];
            return res;
        }
    }
    int cherryPickup(vector<vector<int>>& grid) {

        vector<vector<vector<int>>> memo(
            grid.size(), vector<vector<int>>(
                             grid[0].size(),
                             vector<int>(grid[0].size(), -1))); //-1表示没有记忆
        return dfs(memo, grid, 0, 0, grid[0].size() - 1);
    }
};
int main() {
    vector<vector<int>> grid =  {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    Solution s;
    std::cout << s.cherryPickup(grid) << endl;
    return 0;
}