/*

Kth Smallest
Difficulty: MediumAccuracy: 35.17%Submissions: 747K+Points: 4Average Time: 25m
Given an integer array arr[] and an integer k, your task is to find and return the kth smallest element in the given array.

Note: The kth smallest element is determined based on the sorted order of the array.

Examples :

Input: arr[] = [10, 5, 4, 3, 48, 6, 2, 33, 53, 10], k = 4
Output: 5
Explanation: 4th smallest element in the given array is 5.
Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output: 7
Explanation: 3rd smallest element in the given array is 7.
Constraints:
1 = arr.size() = 105
1 = arr[i] = 105
1 = k =  arr.size() 

*/


class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int>pq;
        
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        
        for(int i=k;i<arr.size();i++){
            if(arr[i]>=pq.top()){
                continue;
            }
            
            pq.pop();
            pq.push(arr[i]);
        }
        
        return pq.top();
    }
};
