/*
Given a string S of length N, you have to output the length of the longest substring of S with non-repeating characters.
*/

#include<iostream>
#include<string.h>
using namespace std;


class Solution {
public:
    int longestUniqueSubstring(string s) {
        // write your code here 
        unordered_set<char> st;
        int left=0,right=0;
        
        int maxlen=0;
        
        while(right<s.length()){
            
            if(st.find(s[right])==st.end()){
                st.insert(s[right]);
                maxlen=max(maxlen,right-left+1);
                
                right++;
            }else{
                st.erase(s[left]);
                left++;
            }
        }
        
        return maxlen;
    }
};
