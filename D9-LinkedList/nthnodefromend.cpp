/*19. Remove Nth Node From End of List
Medium


Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            int size = 0;
            ListNode* curr = head;
            ListNode* last = head;
            ListNode* temp = head;

            while(curr!=NULL)
            {
                    size++;
                    curr = curr->next;
            }
            
            if(n==1)
            {
                    if(n==size)
                    {
                            return NULL;
                    }
                    while(last->next->next!=NULL)
                    {
                            last = last->next;
                    }
                    
                    last->next = NULL;
                    return head;
            }
            
            
            
            else if(n==size)
            {
                    return head->next;
            }
            
            else
            {
            
            int t = size - n;
            //cout<<t<<endl;        
            int k = 0;
            while(k!=t-1)
            {
                    temp = temp->next;
                    k++;
            
            }
            //cout<<temp->val;        
            if(temp->next!=NULL && temp->next->next!=NULL)        
            temp->next = temp->next->next;
            //temp = head;        
            }
            temp = head;
            return temp;
                    
    }
};