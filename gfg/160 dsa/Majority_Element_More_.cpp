/*
Given an array arr[] consisting of n integers, the task is to find all the array elements which occurs more than floor(n/3) times.

Note: The returned array of majority elements should be sorted.

Examples:

Input: arr[] = [2, 2, 3, 1, 3, 2, 1, 1]
Output: [1, 2]
Explanation: The frequency of 1 and 2 is 3, which is more than floor n/3 (8/3 = 2).
*/


class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        
        // Code here
        
        int n=arr.size();
        map<int,int>freq;
        vector<int>majority;
        
        for(int n:arr){
            freq[n]++;
        }
        
        for(auto it:freq){
            if(it.second>n/3){
                majority.push_back(it.first);
            }
        }
        
       sort(majority.begin(),majority.end());
       return majority;
    }
};
