#include <iostream>
#include <vector>

using namespace std;
//关闭读写
static const auto _____ = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
public:
    // O(m+n)
    /*double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
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
    }*/


    //  O (log(m+n))
    //
    //        left_part          |        right_part
    //  A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
    //  B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
    //
    //  If we can ensure:
    //    1. len(left_part) = len(right_part)
    //    2. max(left_part) ≤ min(right_part)
    //  Then:
    //    median = [max(left_part) + min(right_part)] / 2
    //
    //  ==>
    //    1. i+j = m−i+n−j ==> j = (m+n-2i)/2 or j = (m+n+1-2i)/2
    //       j ≥ 0 && 0 ≤ i ≤ m ==> n-m ≥ 0 ==> n ≥ m
    //    2. A[i-1] ≤ B[j] && B[j-1] ≤ A[i]
    //
    //  ==>
    //    1. (j = 0 or i = m or B[j−1] ≤ A[i]) && (i = 0 or j = n or A[i−1] ≤ B[j]) ==> i is perfect
    //    2. j > 0 and i < m and B[j−1] > A[i] ==> i is too small , we must increase it
    //    3. i > 0 and j < n and A[i−1] > B[j] ==> i is too big , we must decrease it
    //

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m, n;
        m = static_cast<int>(nums1.size());
        n = static_cast<int>(nums2.size());
        if (m > n)
        {
            swap(m, n);
            swap(nums1, nums2);
            //swap 比 调用自身函数(递归)快
//            return findMedianSortedArrays(nums2, nums1);
        }

        int imin = 0, imax = m;
        int k = (m + n + 1) / 2;
        int i = 0, j = 0;
        while (imin <= imax)
        {
            i = (imin + imax) >> 1;
            j = k - i;
            if (j > 0 && i < m && nums2[j - 1] > nums1[i]) ++imin;
            else if (i > 0 && j < n && nums1[i - 1] > nums2[j]) --imax;
            else break;
        }

        int n1, n2;
        //left is null
        if (!i) n1 = nums2[j - 1];
        else if (!j) n1 = nums1[i - 1];
        else n1 = max(nums1[i - 1], nums2[j - 1]);
        if ((m + n) & 1)return n1;

        //right is null
        if (i == m) n2 = nums2[j];
        else if (j == n) n2 = nums1[i];
        else n2 = min(nums1[i], nums2[j]);
        return (n1 + n2) / 2.0;
    }
};

int main()
{
    Solution s;
    vector<int> n1{1, 2};
    vector<int> n2{3, 4};
//    cout<<n2.size();
    cout << s.findMedianSortedArrays(n1, n2);

    return 0;
}