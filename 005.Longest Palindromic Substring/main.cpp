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
    //直接动态规划 O(n^2)
    //X={x1,x2,...,xi,...,xj,...xm} i<=j
    //        {       1         i==j
    //dp[i,j]={  dp[i+1,j-1]+2  i<j && xi==xj && dp[i+1,j-1] > 0
    //        {       2         i<j && xi==xj && i+1==j
    //        {       0         i<j && xi==xj && dp[i+1,j-1] == 0
    //        {       0         i<j && xi!=xj
    //        {    dp[j,i]      i>j
    // 注意要用递归函数dpf(i,j),而不直接使用数组dp[i][j],保证引用的数据一定是已经计算过的
    //time: 523ms beats 2.32%  ==> 427ms 2.23%
    string longestPalindrome0(string s)
    {
        auto m = static_cast<int>(s.length());
        vector<vector<int >> dp(m, vector<int>(m));
        int max = 0, mi = 0, mj = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (dpf(i, j, dp, s) > max && dpf(i, j, dp, s) <= 1000 + 1)
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
        //dp[][] all +1
        if (dp[i][j] != -1 + 1)
            return dp[i][j];
        if (i == j)
        {
            dp[i][j] = 1 + 1;
        } else if (i > j)
        {
            dp[i][j] = dpf(j, i, dp, s);

        } else if (s[i] == s[j] && i + 1 == j)
        {
            dp[i][j] = 2 + 1;
        } else if (s[i] == s[j] && dpf(i + 1, j - 1, dp, s) > 0 + 1)
        {
            dp[i][j] = dp[i + 1][j - 1] + 2;
        } else
        {
            dp[i][j] = 0 + 1;
        }
        return dp[i][j];
    }


    //采用正序反序求LCS最长公共子串 O(n^2)
    //X={x1,x2,...,xi,...xm}
    //Y={y1,y2,...,yj,...yn}
    //定义dp[i,j] 结尾为xi与yj的公共子串的长度
    //         { 0                xi!=yj
    //dp[i,j]= { dp[i-1,j-1]+1    xi==yj
    //         { 1             (i==0 || j==0) && xi==yj
    //注意：LCS可能不不是回文串 例如: abcdqwerdcba ==> LCS:abcd
    //    需要进行check
    // Time: 412ms  beats 3.40%
    string longestPalindrome1(string s)
    {
        auto m = s.length();
        vector<vector<int>> dp(m, vector<int>(m));
        auto max = 0;
        auto mi = 0, mj = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (s[i] != s[m - j - 1])
                    dp[i][j] = 0;
                else if ((i == 0 || j == 0) && s[i] == s[m - j - 1])
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                if (dp[i][j] > max && dp[i][j] <= 1000)
                {
                    auto canditate = s.substr(1 + i - dp[i][j], dp[i][j]);
                    auto resubstr = canditate;
                    reverse(resubstr.begin(), resubstr.end());
                    //check
                    if (resubstr == canditate)
                    {
                        max = dp[i][j];
                        mi = i;
                        mj = j;
                    }
                }
            }
        }
        return s.substr(1 + mi - max, max);
    }


    //Expand around center O(n^2)
    // time: 4ms beats 93.89%
    string longestPalindrome(string s)
    {
        if (s.size() < 2)
            return s;
        int len = s.size(), max_left = 0, max_len = 1, left, right;
        //len - start > max_len / 2 此句会大幅加快搜索速度，分支限界
        for (int start = 0; start < len && len - start > max_len / 2;)
        {
            left = right = start;
            //中间部分相同
            while (right < len - 1 && s[right] == s[right + 1]) ++right;
            start = right + 1;
            while (right < len - 1 && s[right + 1] == s[left - 1])
            {
                ++right;
                --left;
            }
            if (max_len < right - left + 1)
            {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }



    //Manacher's Algorithm O(n)


};

int main()
{
    Solution solution;
    std::cout << solution.longestPalindrome("aaabcdasdfghjkldcbaaa") << std::endl;
    return 0;
}