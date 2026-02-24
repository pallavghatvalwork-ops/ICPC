/*

409. Longest Palindrome
Solved
Easy
Topics
premium lock icon
Companies
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 

Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only

*/


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;
        int res=0;
        bool isOdd=false;
        int max_ch=INT_MIN;
        for(int i=0;i<s.size();i++){
            f[s[i]]++;
        }

        for(auto i:f){
            if(i.second%2==0){
                res+=i.second;
            }else{
                res+=i.second-1;
                isOdd=true;
            }
        }

        if(isOdd){
            res=res+1;
        }
        

        return res;
    }
};
