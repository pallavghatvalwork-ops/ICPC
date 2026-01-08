/*

Kadane's Algorithm
Difficulty: MediumAccuracy: 36.28%Submissions: 1.2MPoints: 4Average Time: 20m
You are given an integer array arr[]. You need to find the maximum sum of a subarray (containing at least one element) in the array arr[].

Note : A subarray is a continuous part of an array.

Examples:

Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.

*/

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int res=arr[0];
        int maxEnd=arr[0];
        
        for(int i=1;i<arr.size();i++){
            maxEnd=max(maxEnd+arr[i],arr[i]);
            res=max(res,maxEnd);
        }
        return res;
    }
};
