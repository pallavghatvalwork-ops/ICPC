/*

3. Longest Substring Without Repeating Characters
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int low=0,high=0,res=0;
       int n=s.size();
       unordered_map<char,int>f;
       for(int high=0;high<n;high++){
            f[s[high]]++;

            int k=high-low+1;

            while(f.size()<k){
                f[s[low]]--;
                if(f[s[low]]==0){
                    f.erase(s[low]);
                }
                low++;
                k=high-low+1;
            }

            int len=high-low+1;
            res=max(res,len);
       }
       return res;
    }
};
