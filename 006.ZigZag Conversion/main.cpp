#include <iostream>
#include <vector>

using namespace std;

static const auto ______ = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
public:
    // O(n)
    string convert0(string s, int numRows)
    {
        vector<string> zigzag;
        zigzag.resize(numRows);
        auto len = s.length();
        for (int l = 0; l < numRows; ++l)
        {
            zigzag[l].reserve(len / numRows);
        }

        auto i = 0, j = 0;
        while (i < len)
        {
            if (j == 0)
            {
                while (j < numRows - 1)
                {
                    zigzag[j++].push_back(s[i++]);
                }
            }
            if (j == numRows - 1)
            {
                while (j > 0)
                {
                    zigzag[j--].push_back(s[i++]);
                }
            }
        }
        string zigstr{};
        for (int k = 0; k < numRows; ++k)
        {
            zigstr += zigzag[k];
        }
        return zigstr;
    }


    //
    string convert(string s, int numRows)
    {
        auto len = s.length();
        if (len <= 1 || len <= numRows || numRows == 1)
            return s;
        string zigstr = "";
        zigstr.reserve(len);
        for (int j = 0; j < numRows; ++j)
        {
            for (int i = 0; i * (2 * numRows - 2) + j < len; ++i)
            {
//                zigstr.push_back(s[i * (2 * numRows - 2) + j]);
                zigstr += s[i * (2 * numRows - 2) + j];
                if (j != 0 && j != numRows - 1)
//                    zigstr.push_back(s[(i + 1) * (2 * numRows - 2) - j]);
                    zigstr += s[(i + 1) * (2 * numRows - 2) - j];
            }
        }
        return zigstr;
    }
};

int main()
{
    Solution solution;
    std::cout << solution.convert("ABCDE", 4) << std::endl;
    return 0;
}