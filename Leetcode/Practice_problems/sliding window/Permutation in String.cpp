/*

567. Permutation in String
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 

Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
 

Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.

*/

class Solution {
    bool areVectorEqual(vector<int>&a,vector<int>&b){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.length();
        int low=0;
        vector<int>fs2(26,0);
        vector<int>fs1(26,0);
        if(s2.size()<s1.size()){
            return false;
        }
        
        for(int i=0;i<s1.size();i++){
            fs1[s1[i]-'a']++;
        }

        for(int high=0;high<n;high++){
            fs2[s2[high]-'a']++;

            if(high-low+1>s1.size()){
                fs2[s2[low]-'a']--;
                low++;
            }

            if(high-low+1==s1.size()){
                if(areVectorEqual(fs1,fs2)){
                    return true;
                }

            }
           
        }

        return false;
    }
};
