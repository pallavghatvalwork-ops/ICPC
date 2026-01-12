/*

977. Squares of a Sorted Array
Solved
Easy
Topics
premium lock icon
Companies
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.

*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>neg;
        vector<int>pos;

        for(int i=0;i<n;i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }else{
                neg.push_back(nums[i]);
            }
        }

        if(neg.size()==0){
            for(int i=0;i<pos.size();i++){
                pos[i]=pos[i]*pos[i];
            }
            return pos;
        }

        if(neg.size()==0){
           for(int i=0;i<neg.size();i++){
                neg[i]=neg[i]*neg[i];
            }
            reverse(neg.begin(),neg.end());
            return neg;
        }

        for(int i=0;i<pos.size();i++){
            pos[i]=pos[i]*pos[i];
        }

        for(int i=0;i<neg.size();i++){
                neg[i]=neg[i]*neg[i];
        }
        reverse(neg.begin(),neg.end());

        vector <int>res(neg.size()+pos.size());

        int i=0,j=0,id=0;

        while(i<neg.size() && j<pos.size()){

            if(neg[i]<=pos[j]){
                res[id]=neg[i];
                i++;
                id++;
            }else{
                res[id]=pos[j];
                j++;
                id++;
            }
        }
        
        while(j<pos.size()){
            res[id]=pos[j];
            j++;
            id++;
        }

        while(i<neg.size()){
            res[id]=neg[i];
            i++;
            id++;
        }
        return res;
    }
};
