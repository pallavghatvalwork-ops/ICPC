/*

234. Palindrome Linked List
Solved
Easy
Topics
premium lock icon
Companies
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?

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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return true;
        }
        ListNode*slow=head;
        ListNode*fast=head;

        while(fast!=NULL && fast->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;

        }

        if(fast!=NULL){
            slow=slow->next;
        }

        ListNode*curr=slow;
        ListNode*prev=NULL;

        while(curr!=NULL){
            ListNode*temp=curr->next;

            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        ListNode*first=head;
        ListNode*second=prev;

        while(second!=NULL){
            if(first->val!=second->val){
                return false;
            }

            first=first->next;
            second=second->next;
        }
        return true;
    }
};
