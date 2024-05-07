# 算法设计课程设计

动态规划算法的应用与实现

## [1463.](https://leetcode.cn/problems/cherry-pickup-ii/)[摘樱桃](https://leetcode.cn/problems/cherry-pickup-ii/)[II](https://leetcode.cn/problems/cherry-pickup-ii/)

### 问题描述

给你一个 `rows x cols` 的矩阵 `grid` 来表示一块樱桃地。 `grid` 中每个格子的数字表示你能获得的樱桃数目。

你有两个机器人帮你收集樱桃，机器人 1 从左上角格子 `(0,0)` 出发，机器人 2 从右上角格子 `(0, cols-1)` 出发。

请你按照如下规则，返回两个机器人能收集的最多樱桃数目：

* 从格子 `(i,j)` 出发，机器人可以移动到格子 `(i+1, j-1)`，`(i+1, j)` 或者 `(i+1, j+1)` 。
* 当一个机器人经过某个格子时，它会把该格子内所有的樱桃都摘走，然后这个位置会变成空格子，即没有樱桃的格子。
* 当两个机器人同时到达同一个格子时，它们中只有一个可以摘到樱桃。
* 两个机器人在任意时刻都不能移动到 `grid` 外面。
* 两个机器人最后都要到达 `grid` 最底下一行。

**示例 1：**

![1](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/30/sample_1_1802.png)

<pre><strong>输入：</strong>grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
<strong>输出：</strong>24
<strong>解释：</strong>机器人 1 和机器人 2 的路径在上图中分别用绿色和蓝色表示。
机器人 1 摘的樱桃数目为 (3 + 2 + 5 + 2) = 12 。
机器人 2 摘的樱桃数目为 (1 + 5 + 5 + 1) = 12 。
樱桃总数为： 12 + 12 = 24 。
</pre>

**示例 2：**

![2](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/05/30/sample_2_1802.png)

<pre><strong>输入：</strong>grid = [[1,0,0,0,0,0,1],[2,0,0,0,0,3,0],[2,0,9,0,0,0,0],[0,3,0,5,4,0,0],[1,0,2,3,0,0,6]]
<strong>输出：</strong>28
<strong>解释：</strong>机器人 1 和机器人 2 的路径在上图中分别用绿色和蓝色表示。
机器人 1 摘的樱桃数目为 (1 + 9 + 5 + 2) = 17 。
机器人 2 摘的樱桃数目为 (1 + 3 + 4 + 3) = 11 。
樱桃总数为： 17 + 11 = 28 。
</pre>

**示例 3：**

<pre><strong>输入：</strong>grid = [[1,0,0,3],[0,0,0,3],[0,0,3,3],[9,0,3,3]]
<strong>输出：</strong>22
</pre>

**示例 4：**

<pre><strong>输入：</strong>grid = [[1,1],[1,1]]
<strong>输出：</strong>4
</pre>

**提示：**

* `rows == grid.length`
* `cols == grid[i].length`
* `2 <= rows, cols <= 70`
* `0 <= grid[i][j] <= 100`

### 解题思路

## [2957.](https://leetcode.cn/problems/remove-adjacent-almost-equal-characters/)[消除相邻近似相等字符](https://leetcode.cn/problems/remove-adjacent-almost-equal-characters/)

### 问题描述

给你一个下标从 **0** 开始的字符串 `word` 。

一次操作中，你可以选择 `word` 中任意一个下标 `i` ，将 `word[i]` 修改成任意一个小写英文字母。

请你返回消除 `word` 中所有相邻 **近似相等** 字符的 **最少** 操作次数。

两个字符 `a` 和 `b` 如果满足 `a == b` 或者 `a` 和 `b` 在字母表中是相邻的，那么我们称它们是 **近似相等** 字符。

**示例 1：**

<pre><b>输入：</b>word = "aaaaa"
<b>输出：</b>2
<b>解释：</b>我们将 word 变为 "a<em><strong>c</strong></em>a<em><strong>c</strong></em>a" ，该字符串没有相邻近似相等字符。
消除 word 中所有相邻近似相等字符最少需要 2 次操作。
</pre>

**示例 2：**

<pre><b>输入：</b>word = "abddez"
<b>输出：</b>2
<b>解释：</b>我们将 word 变为 "<em><strong>y</strong></em>bd<em><strong>o</strong></em>ez" ，该字符串没有相邻近似相等字符。
消除 word 中所有相邻近似相等字符最少需要 2 次操作。</pre>

**示例 3：**

<pre><b>输入：</b>word = "zyxyxyz"
<b>输出：</b>3
<b>解释：</b>我们将 word 变为 "z<em><strong>a</strong></em>x<em><strong>a</strong></em>x<em><strong>a</strong></em>z" ，该字符串没有相邻近似相等字符。
消除 word 中所有相邻近似相等字符最少需要 3 次操作
</pre>

**提示：**

* `1 <= word.length <= 100`
* `word` 只包含小写英文字母。

### 解题思路

第一步创建初始数组，那么我们就设置一个dp数组用来存储次数，dp[i]就表示消除前i个字符中所有相邻的近似相等字符的最小操作次数。

确定状态转移方程：

$$
dp[i] = dp[i-2] + 1 \quad \text{如果} \quad word[i] \approx word[i-1]\\
dp[i] = dp[i-1]  \quad \text{其他情况}
$$

当word[i]和word[i-1]近似相等之时，我们选择消除word[i-1]，保证了他与word[i-2]、word[i]互不相等，加上原有次数后dp[i] = dp[i-2] + 1，再进行继续搜索操作。直到整个字符串被遍历完毕。

对于初始状态的dp[0]，我们置零，对于dp[1]我们按照上述规则，如果0和1近似相等，我们就置dp[1] = 1，否则dp[1] = 0。

```cpp
class Solution {
public:
    bool isapprox(char a, char b) {
        return (a - b) == 1 || a == b || (b - a) == 1;
    }
    int removeAlmostEqualCharacters(string word) {

        int n = word.size();
        if (n == 1)
            return 0;
        vector<int> dp(n);
        dp[0] = 0;
        if (isapprox(word[0], word[1]))
            dp[1] = 1;
        else
            dp[1] = 0;
        for (int i = 2; i < word.size(); i++) {
            if (isapprox(word[i], word[i - 1]))
                dp[i] = dp[i - 2] + 1;
            else
                dp[i] = dp[i - 1];
        }
        return dp[n - 1];
    }
};
```

在这串代码中我们不难发现，其时间、空间复杂度均达到了O(n),再观察发现，我们并不需要存储所有的dp数组，我们只需要存储dp[i-2]和dp[i-1]即可，所以我们可以将空间复杂度降低到O(1)。

```cpp
class Solution {
public:
    bool isapprox(char a, char b) {
        return (a - b) == 1 || a == b || (b - a) == 1;
    }
    int removeAlmostEqualCharacters(string word) {

        int n = word.size();
        if (n == 1)
            return 0;
        vector<int> dp(2);
        dp[0] = 0;
        if (isapprox(word[0], word[1]))
            dp[1] = 1;
        else
            dp[1] = 0;
        for (int i = 2; i < word.size(); i++) {
            int tmp = dp[1];
            if (isapprox(word[i], word[i - 1])) {
                dp[1] = dp[0] + 1;
                dp[0] = tmp;
            } else {
                dp[0] = dp[1];
            }
        }
        return dp[1];
    }
};
```

此时的空间复杂度就降低到了O(1)
