/*
234. Palindrome Linked List
Easy

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?
*/
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


/*Approach
Find the middle of linked list first.
After that reverse the second half of linked list now after that start traversing the
first half from begin and second half from end.
*/

auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
public:
    bool isPalindrome(ListNode* head) {
            if(head==NULL || head->next==NULL)
                    return true;
            int size = 1;
            ListNode* tail = head;
            ListNode* prev = NULL;
            ListNode* next = NULL;
            while(tail->next!=NULL)
            {
                    size++;
                    tail = tail->next;
            }
            
            tail = head;
            for(int i=0;i<size/2;i++)
            {
                    tail = tail->next;
            }
            
            for(int i=size/2;i<size;i++)
            {
                    next = tail->next;
                    tail->next = prev;
                    prev = tail;
                    tail = next;
            }
            
            next = prev;
            prev = head;
            
            while(next!=NULL && prev!=next)
            {
                    if(next->val!=prev->val)
                            return false;
                    prev = prev->next;
                    next = next->next;
            }
            
            return true;
            
        
    }
};