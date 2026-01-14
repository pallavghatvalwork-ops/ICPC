/*


16. 3Sum Closest
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104

*/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff_max= INT_MAX;
        int res=0;
        int n=nums.size(); 
        for(int i=0;i<n-2;i++){
            
            int left=i+1,right=n-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                int diff=abs(sum-target);
                if(diff<diff_max){

                    diff_max=diff;
                    res=sum;
                }else if(sum>target){
                    right--;
                }else{
                    left++;
                }
            }

        }

        return res;
    }
};
