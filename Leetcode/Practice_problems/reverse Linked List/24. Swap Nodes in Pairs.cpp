/*

24. Swap Nodes in Pairs
Solved
Medium
Topics
premium lock icon
Companies
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]

Explanation:



Example 2:

Input: head = []

Output: []

Example 3:

Input: head = [1]

Output: [1]

Example 4:

Input: head = [1,2,3]

Output: [2,1,3]

 

Constraints:

The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

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


    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode*left=head;
        ListNode*right;
        ListNode*res=NULL;
        ListNode*prevleft=NULL;
        int size=2;

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
