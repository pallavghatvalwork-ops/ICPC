/*

Minimize the Heights II
Difficulty: MediumAccuracy: 15.06%Submissions: 766K+Points: 4Average Time: 25m
Given an array arr[] denoting heights of n towers and a positive integer k.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by k
Decrease the height of the tower by k
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by k for each tower. After the operation, the resultant array should not contain any negative integers.

Examples :

Input: k = 2, arr[] = [1, 5, 8, 10]
Output: 5
Explanation: The array can be modified as [1+k, 5-k, 8-k, 10-k] = [3, 3, 6, 8]. The difference between the largest and the smallest is 8-3 = 5.

*/


class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int diff=arr[n-1]-arr[0];
        
        int smallest=arr[0]+k;
        int largest=arr[n-1]-k;
        
        
        for(int i=1;i<n;i++){
            
            if(arr[i]-k<0){
                continue;
            }
            
            int mn=min(smallest,arr[i]-k);
            int mx=max(largest,arr[i-1]+k);
            
            diff=min(diff,mx-mn);
            
        }
        
       
        
        return diff;
    }
};
