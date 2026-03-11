/*

25. Reverse Nodes in k-Group
Solved
Hard
Topics
premium lock icon
Companies
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?

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
    void reverse(ListNode*head,int times){
        ListNode*curr=head;
        ListNode*prev=NULL;

        while(times--){
            ListNode*nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode*left=head;
        ListNode*right;
        ListNode*res=NULL;
        ListNode*prevleft=NULL;
        int size=k;

        while(true){
            right=left;
            for(int i=0;i<size-1;i++){
                if(right==NULL){
                    break;
                }
                right=right->next;
            }

            if(right){
                ListNode*nextleft=right->next;
                reverse(left,size);

                if(prevleft){
                    prevleft->next=right;
                }
                prevleft=left;

                if(res==NULL){
                    res=right;
                }

                left=nextleft;
            }else{

                if(prevleft){
                    prevleft->next=left;
                    if(res==NULL){
                        res=left;
                    }
                }

                break;
            }
        }
        return res;
    }
};
