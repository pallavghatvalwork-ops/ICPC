/*

34. Find First and Last Position of Element in Sorted Array
Solved
Medium
Topics
premium lock icon
Companies
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

*/



class Solution {
    int first(vector<int>& nums,int target){
        int low=0,high=nums.size()-1;
        int left=-1;
    
        while(low<=high){

            int mid=low+(high-low)/2;

            if(nums[mid]==target){
                left=mid;
                high=mid-1;
            }else if(target>nums[mid]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return left;
    }

    int last(vector<int>& nums,int target){

        int low=0,high=nums.size()-1;
        int right=-1;

        while(low<=high){

            int mid=low+(high-low)/2;

            if(nums[mid]==target){
                right=mid;
                low=mid+1;
            }else if(target>nums[mid]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }

        return right;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      
        
        int left=first(nums,target);
        int right=last(nums,target);

        return {left,right};
    }
};
