#include <iostream>
#include <vector>

using namespace std;

static const auto _____ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

//KEY: LCS 最长公共子串 最长公共子序列
class Solution
{
public:
    //采用正序反序求LCS
    //X={x1,x2,...,xi,...xm}
    //Y={y1,y2,...,yj,...yn}
    //定义dp[i,j] 结尾为xi与yj的公共子串的长度
    //         { 0                xi!=yj
    //dp[i,j]= { dp[i-1,j-1]+1    xi==yj
    //         { 0             i==0 or j==0




    //直接动态规划
    //X={x1,x2,...,xi,...,xj,...xm} i<=j
    //        {       1         i==j
    //dp[i,j]={  dp[i+1,j-1]+2  i<j && xi==xj && dp[i+1,j-1] > 0
    //        {       2         i<j && xi==xj && i+1==j
    //        {       0         i<j && xi==xj && dp[i+1,j-1] == 0
    //        {       0         i<j && xi!=xj
    //        {    dp[j,i]      i>j
    // 注意要用递归函数dpf(i,j),而不直接使用数组dp[i][j],保证引用的数据一定是已经计算过的
    //time: 523ms beats 2.32%
    string longestPalindrome(string s)
    {
        auto m = static_cast<int>(s.length());
        vector<vector<int >> dp(m, vector<int>(m));
        int max = 0, mi = 0, mj = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                dp[i][j] = -1;
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (dpf(i, j, dp, s) > max && dpf(i, j, dp, s) <= 1000)
                {
                    max = dp[i][j];
                    mi = std::min(i, j);
                    mj = std::max(i, j);
                }
            }
        }
        return s.substr(mi, mj - mi + 1);

    }

    int dpf(int i, int j, vector<vector<int >> &dp, const string &s)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == j)
        {
            dp[i][j] = 1;
        } else if (i > j)
        {
            dp[i][j] = dpf(j, i, dp, s);

        } else if (s[i] == s[j] && i + 1 == j)
        {
            dp[i][j] = 2;
        } else if (s[i] == s[j] && dpf(i + 1, j - 1, dp, s) > 0)
        {
            dp[i][j] = dp[i + 1][j - 1] + 2;
        } else
        {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }
};

int main()
{
    Solution solution;
    std::cout << solution.longestPalindrome("cbnhgabagfde") << std::endl;
    return 0;
}