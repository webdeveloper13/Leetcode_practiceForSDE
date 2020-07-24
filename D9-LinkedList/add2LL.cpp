/*
2. Add Two Numbers
Medium
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* ans = new ListNode(0);
            ListNode* temp = ans;
            int carry = 0;
            while(l1 || l2)
            {
                    int val1 = (l1)?l1->val:0;
                    int val2 = (l2)?l2->val:0;
                    int val = val1+val2+carry;
                    if(val>=10)
                    {
                            val -= 10;
                            carry = 1;
                    }
                    else
                    {
                            carry = 0;
                    }
                    ListNode* dummy = new ListNode(val);
                    temp->next = dummy;
                    temp = temp->next;
                    l1 = (l1)?l1->next:l1;
                    l2 = (l2)?l2->next:l2;
                    
            }
            if(carry)
            {
                    ListNode* dummy = new ListNode(carry);
                    temp->next = dummy;
            }
            
            return ans->next;
            
        
    }
};