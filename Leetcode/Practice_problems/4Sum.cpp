/*

18. 4Sum
Solved
Medium
Topics
premium lock icon
Companies
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109

*/



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;

        int n=nums.size();

        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n-2;j++){
                if(j!=i+1 && nums[j]==nums[j-1]){
                    continue;
                }

                int low=j+1;
                int high=n-1;

                while(low<high){

                    long long sum=(long long)nums[i]+nums[j]+nums[low]+nums[high];

                    if(target==sum){
                        res.push_back({nums[i],nums[j],nums[low],nums[high]});
                        low++;
                        high--;

                        while(low<high && nums[low]==nums[low-1]){
                            low++;
                        }

                        while(low<high && nums[high]==nums[high+1]){
                            high--;
                        }
                    }else if(sum>target){
                        high--;
                    }else{
                        low++;
                    }
                }

            }
        }

        return res;
    }
};
