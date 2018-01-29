#include <iostream>

using namespace std;

static const auto ______ = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int str_hash[127] = {};
        int l_max = 0, l_now = 0;
        int last_position = 0;
        auto l = s.length();
        for (int i = 0; i < l; ++i)
        {
            auto &now_position_is_exist = str_hash[s[i]];
            if (now_position_is_exist == 0)
            {
                ++l_now;
            } else
            {
                l_now = i - now_position_is_exist + 1;
                for (int j = last_position; j < now_position_is_exist - 1; ++j)
                {
                    str_hash[s[j]] = 0;
                }
                last_position = now_position_is_exist;
            }
            now_position_is_exist = i + 1;
            if (l_now > l_max)
                l_max = l_now;
        }
        return l_max;
    }
};

int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("bcabcb") << endl;
    return 0;
}