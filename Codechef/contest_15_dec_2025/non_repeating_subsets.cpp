/*
You are given a set of integers represented by an array arr, which may contain duplicate elements. Your task is to write a recursive function to generate all unique subsets of this array. Each subset should be unique, even if the array contains duplicate elements. The solution should not generate any duplicate subsets.

A subset of a set is a collection of elements that are all derived from the original set. Subsets can range from the empty set (containing no elements) to the set itself (containing all elements).
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(int index,vector<int>& arr,vector<int>& curr,vector<vector<int>>& ans){
    
        ans.push_back(curr);
        
        for(int i=index;i<arr.size();i++){
            
            if(i>index && arr[i]==arr[i-1]){
                continue;
            }
            
            curr.push_back(arr[i]);
            solve(i+1,arr,curr,ans);
            curr.pop_back();
            
        }
}

vector<vector<int>> uniqueSubsets(vector<int>& multiset) {
    // Write your code here
    vector<vector<int>> ans;
    vector<int> curr;
    
    sort(multiset.begin(),multiset.end());
    
    solve(0,multiset,curr,ans);
    
    return ans;
    
}

