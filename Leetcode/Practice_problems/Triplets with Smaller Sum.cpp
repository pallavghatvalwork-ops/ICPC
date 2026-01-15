/*

Triplets with Smaller Sum
Difficulty: MediumAccuracy: 40.33%Submissions: 105K+Points: 4
Given an array arr[] of distinct integers of size n and a value sum, the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.


Examples :


Input: n = 4, sum = 2, arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with sum less than 2 (-2, 0, 1) and (-2, 0, 3). 
Input: n = 5, sum = 12, arr[] = {5, 1, 3, 4, 7}
Output: 4
Explanation: Below are triplets with sum less than 12 (1, 3, 4), (1, 3, 5), (1, 3, 7) and (1, 4, 5).
Expected Time Complexity: O(N2).
Expected Auxiliary Space: O(1).

*/

class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
       
        sort(arr,arr+n);
        long long ans=0;
        
        
        for(int i=0;i<n;i++){
            int left=i+1,right=n-1;
            
            while(left<right){
                
                long long ogsum=arr[i]+arr[left]+arr[right];
                
                if(ogsum>=sum){
                    right--;
                }else{
                    ans=ans+(right-left);
                    left++;
                    
                }
            }
        }
        
        return ans;
        
    }
};
