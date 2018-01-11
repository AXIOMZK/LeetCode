#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        auto l = nums1.size() + nums2.size();
        int i = 0, j = 0;
        vector<int> median;
        median.reserve(l);

        while (i + j <= l / 2)
        {
            if (nums1.empty())
            {
                median = nums2;
                break;
            }
            if (nums2.empty())
            {
                median = nums1;
                break;
            }
            if (i < nums1.size() && nums1[i] < nums2[j]
                || j == nums2.size())
            {
                median.push_back(nums1[i]);
                ++i;
            } else
            {
                median.push_back(nums2[j]);
                ++j;
            }
        }
        return l % 2 ? (double) median[l / 2] :
               (median[l / 2 - 1] + median[l / 2]) / 2.0;
    }
};

int main()
{
    Solution s;
    vector<int> n1{1, 6};
    vector<int> n2{};
//    cout<<n2.size();
    cout << s.findMedianSortedArrays(n1, n2);

    return 0;
}