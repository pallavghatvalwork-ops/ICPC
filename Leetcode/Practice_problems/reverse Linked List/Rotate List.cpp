/*

61. Rotate List
Solved
Medium
Topics
premium lock icon
Companies
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }

        ListNode*last=head;
        int n=1;

        while(last->next!=NULL){
            n++;
            last=last->next;
        }

        k=k%n;
        if(k==0){
            return head;
        }

        ListNode*t=head;
        int count=1;

        while(t!=NULL){
            if(count==(n-k)){
                break;
            }
            count++;
            t=t->next;
        }

        last->next=head;
        ListNode*res=t->next;
        t->next=NULL;

        return res;
    }
};
