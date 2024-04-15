#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<int>> gcds; // 存储互质数
    vector<vector<int>> tmp;// 存储每个节点的访问顺序
    vector<vector<int>> g;// 邻接表
    vector<int> dep;// 存储每个节点的深度
    vector<int> ans;// 存储答案
public:
    // 执行深度优先搜索以找到互质数
    void dfs(vector<int> &nums, int x, int depth) {
        dep[x] = depth; // 设置当前节点的深度

        // 在gcds向量中检查互质数
        for (int val : gcds[nums[x]]) {
            if (tmp[val].empty()) {
                continue;
            }
        
            int las = tmp[val].back(); // 获取具有相同gcd的最后访问的节点
            if (ans[x] == -1 || dep[las] > dep[ans[x]]) {
                ans[x] = las; // 如果当前节点的深度更大，则更新答案
            }
        }
        tmp[nums[x]].push_back(x); // 将当前节点添加到tmp向量中

        // 递归访问相邻节点
        for (int val : g[x]) {
            if (dep[val] == -1) { // 检查节点是否已被访问
                dfs(nums, val, depth + 1); // 对未访问的节点执行dfs
            }
        }

        tmp[nums[x]].pop_back(); // 在访问完所有相邻节点后，从tmp向量中移除当前节点
    }

vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        // 深度优先搜索
        int n = nums.size();
        gcds.resize(51);
        tmp.resize(51);
        ans.resize(n, -1);
        dep.resize(n, -1);
        g.resize(n);

        // 构建互质数的向量
        for (int i = 1; i <= 50; i++) {
            for (int j = 1; j <= 50; j++) {
                if (gcd(i, j) == 1) {
                    gcds[i].push_back(j);
                } 
            }
        }
        
        // 构建图的邻接表
        for (const auto &val : edges) {
            g[val[0]].push_back(val[1]);
            g[val[1]].push_back(val[0]);
        }
        
        // 执行深度优先搜索
        dfs(nums, 0, 1);
        
        return ans;
    }
};