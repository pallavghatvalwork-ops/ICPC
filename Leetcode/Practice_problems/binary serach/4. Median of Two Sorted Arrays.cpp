/*
4. Median of Two Sorted Arrays
Solved
Hard
Topics
premium lock icon
Companies
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>&smaller=nums1.size()>nums2.size()?nums2:nums1;
        vector<int>&larger=nums1.size()>nums2.size()?nums1:nums2;

        int total=nums1.size()+nums2.size();

        int low=0,high=smaller.size();

        while(low<=high){
            int partitionX=(low+high)/2;
            int partitionY=(total+1)/2-partitionX;

            int l1=partitionX==0? INT_MIN :smaller[partitionX-1];
            int r1=partitionX==smaller.size()?INT_MAX:smaller[partitionX];

            int l2=partitionY==0?INT_MIN:larger[partitionY-1];
            int r2=partitionY==larger.size()?INT_MAX:larger[partitionY];
            
            if(l1<=r2 && l2<=r1){
                if(total%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }else{
                    return max(l1,l2);
                }
            }

            if(l1>r2){
                high=partitionX-1;
            }else{
                low=partitionX+1;
            }
        }

        return 0;
    }
};
