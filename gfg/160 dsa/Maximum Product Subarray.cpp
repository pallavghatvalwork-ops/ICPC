/*

Maximum Product Subarray
Difficulty: MediumAccuracy: 18.09%Submissions: 490K+Points: 4
Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr[].

Note: It is guaranteed that the answer fits in a 32-bit integer.

Examples

Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is [6, -3, -10] with product = 6 * (-3) * (-10) = 180.

*/

class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int currMax=arr[0];
        int currMin=arr[0];
        int maxProd=arr[0];
        
        
        for(int i=1;i<arr.size();i++){
            
            int temp=max({arr[i],currMax*arr[i],currMin*arr[i]});
            
            currMin=min({arr[i],arr[i]*currMax,arr[i]*currMin});
            
            currMax=temp;
            maxProd=max(maxProd,currMax);
        }
        
        return maxProd;
    }
};
