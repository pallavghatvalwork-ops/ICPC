/*

76. Minimum Window Substring
Solved
Hard
Topics
premium lock icon
Companies
Hint
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?

*/


class Solution {

bool check(vector<int>have,vector<int>needed){

    for(int i=0;i<256;i++){
        if(have[i]<needed[i]){
            return false;
        }
       
    }
     return true;
}
public:
    string minWindow(string s, string t) {
        int low=0,res=INT_MAX,start;

        vector<int>have(256);
        vector<int>needed(256);

         if (t.empty() || s.size() < t.size()){ 
            return "";
         }
        for(int i=0;i<t.size();i++){
            needed[t[i]]++;
        }

        for(int high=0;high<s.size();high++){
            have[s[high]]++;

            while(check(have,needed)){
                int len=high-low+1;

                if(res>len){
                    res=len;
                    start=low;
                }
                have[s[low]]--;
                low++;
            }
        }

        return res==INT_MAX?"":s.substr(start,res);
    }
};
