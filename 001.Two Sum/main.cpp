#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:

    //O(nlogn)时间复杂度
/*    struct indicesAndValue
    {
        int indice;
        int value;

        bool operator<(const indicesAndValue &t) const
        {
            return value < t.value;
        }
    };

//TODO:此处要加STATIC
    static bool compValue(const indicesAndValue &t1, const indicesAndValue &t2)
    {
        return t1.value < t2.value;
    }
    vector<int> twoSum(vector<int> &nums, int target)
     {
         vector<indicesAndValue> vector1;
         for (int i = 0; i < nums.size(); ++i)
         {
             indicesAndValue t;
             t.indice = i;
             t.value = nums[i];
             vector1.push_back(t);
         }
         sort(vector1.begin(), vector1.end(), compValue);
         auto it1 = vector1.begin();
         auto it2 = --vector1.end();
         while ((*it1).value + (*it2).value != target)
         {
             if ((*it1).value + (*it2).value < target)
                 ++it1;
             else --it2;
         }
         vector<int> result;
         result.push_back((*it1).indice);
         result.push_back((*it2).indice);
         return result;
     }*/

    //O(n)时间复杂度
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        //Key is the number and value is its index in the vector.
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < numbers.size(); ++i)
        {
            int numberToFind = target - numbers[i];
            //此处的find的时间复杂度为O(1),因为unorder_map的实现是hash表
            if (hash.find(numberToFind) != hash.end())
            {
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;
            }

            //number was not found. Put it in the map.
            hash[numbers[i]] = i;
        }
        return result;
    }
};


int main()
{
    Solution s;
    vector<int> t{3,1, 2, 4};
    t = s.twoSum(t, 5);
    std::cout << "[" << t[0] << "," << t[1] << "]" << std::endl;
    return 0;
}