#include<vector>
#include<iostream>
using namespace std;
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
int main() {
    string word = "aaaaa";
    Solution s;
    std::cout << s.removeAlmostEqualCharacters(word) << endl;
    return 0;
}