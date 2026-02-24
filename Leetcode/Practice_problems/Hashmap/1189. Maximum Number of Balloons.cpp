/*

1189. Maximum Number of Balloons
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
 

Constraints:

1 <= text.length <= 104
text consists of lower case English letters only.

*/



class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int res=INT_MAX;
        string s="balloon";
        unordered_map<char,int>n;
        unordered_map<char,int>h;

        for(int i=0;i<text.size();i++){
            h[text[i]]++;
        }

        for(int i=0;i<s.size();i++){
            n[s[i]]++;
        }

        for(auto i:n){
            char c=i.first;
            int fn=i.second;
            int fh=h[c];
            int times=fh/fn;

            res=min(res,times);
        }

        return res;

    }
};
