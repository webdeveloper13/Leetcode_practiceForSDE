/*206. Reverse Linked List
Easy
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

//Recursive method
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
            if(head==NULL || head->next==NULL)
            {
                    return head;
            }
            
            ListNode *temp = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return temp;
    }
};

/*
Dry run:
1->2->3->4->5->NULL
*/


//Iterative method
auto i1 = []()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
}();
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        while(head!=NULL)
        {
                ListNode *nextNode = head->next;
                head->next = prev;
                prev=head;
                head = nextNode;
        }
            
        return prev;    
            
    }
};
/*
null->1->2->3->4->5->NULL
 5->4->3->2->1->NULL        
 */