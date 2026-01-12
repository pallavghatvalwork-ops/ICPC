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
    public int[] sortedSquares(int[] nums) {
        int res[] = new int[nums.length];
        int pos=nums.length-1;
        int left=0;
        int right=nums.length-1;

        while(left<=right){

            int ls=nums[left]*nums[left];
            int rs=nums[right]*nums[right];

            if(ls>rs){
                res[pos]=ls;
                left++;
            }else{
                res[pos]=rs;
                right--;
            }

            pos--;
        }
        return res;
    }
}