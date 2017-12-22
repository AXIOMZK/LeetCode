#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    /*ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        string s1, s2, resultStr;
        auto item = l1;
        while (item)
        {
            s1.push_back((char) (item->val + '0'));
            item = item->next;
        }
        reverse(s1.begin(), s1.end());
        item = l2;
        while (item)
        {
            s2.push_back((char) (item->val + '0'));
            item = item->next;
        }
        reverse(s2.begin(), s2.end());
        stringstream stringstream1;
        long long  a, b;
        stringstream1 << s1;
        stringstream1 >> a;
        stringstream1.clear();
        stringstream1 << s2;
        stringstream1 >> b;
        stringstream1.clear();
        long long resultNum = a + b;
//        cout<<a<<"+"<<b<<"="<<resultNum<<endl;
        stringstream1 << resultNum;
        stringstream1 >> resultStr;
        stringstream1.clear();
        reverse(resultStr.begin(), resultStr.end());
        ListNode *resultHead = new ListNode(resultStr[0] - '0');
        ListNode *p;
        auto last = resultHead;
        for (int i = 1; i < resultStr.size(); ++i)
        {
            p = new ListNode(resultStr[i] - '0');
            last->next = p;
            last = p;
        }
        return resultHead;
    }*/
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        auto item1 = l1;
        auto item2 = l2;
        ListNode *resultHead = nullptr, *p = nullptr, *last = nullptr;
        p = resultHead = new ListNode((item1->val + item2->val) % 10);
        int carry = (item1->val + item2->val) / 10;
        while (item1->next || item2->next || carry)
        {
            last = p;
            item1 = item1->next;
            item2 = item2->next;

            if (item1 == nullptr)
            {
                if (!carry)
                {
                    p = item2;
                    last->next = p;
                    break;
                } else
                    item1 = new ListNode(0);

            }
            if (item2 == nullptr)
            {
                if (!carry)
                {
                    p = item1;
                    last->next = p;
                    break;
                } else
                    item2 = new ListNode(0);
            }

            int x = item1->val + item2->val + carry;
            p = new ListNode(x % 10);
            carry = x / 10;
            last->next = p;
        }
        return resultHead;
    }
};

int main()
{
    ListNode l11(1);
    ListNode l12(8);
    ListNode l13(3);
    l11.next = &l12;
    l12.next = &l13;

    ListNode l21(0);
    ListNode l22(6);
    ListNode l23(4);
    l21.next = &l22;
    l22.next = &l23;


    auto it1 = &l11;
    auto it2 = &l21;
//    ListNode *it2=NULL;
    Solution s;
    auto it3 = s.addTwoNumbers(it1, it2);
    while (it3)
    {
        cout << it3->val;
        it3 = it3->next;
    }


    return 0;
}