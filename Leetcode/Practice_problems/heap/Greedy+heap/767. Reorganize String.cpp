/*

767. Reorganize String
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

*/

class Solution {
public:
    string reorganizeString(string s) {
        string res="";
        unordered_map<char,int>f;
        for(int i=0;i<s.size();i++){
            f[s[i]]++;
        }

        priority_queue<pair<int,char>>pq;
        for(auto e:f){
            pq.push({e.second,e.first});
        }

        
        while(!pq.empty()){
           
            pair<int,char>p=pq.top();
            pq.pop();
            if(res.empty() || res.back()!=p.second){
                res.push_back(p.second);
        
                p.first--;
                if(p.first>0){
                    pq.push(p);
                }
            }else{

                if(pq.empty()){
                    return "";
                }

                pair<int,char>p1=pq.top();
                pq.pop();
                res.push_back(p1.second);
                p1.first--;
                if(p1.first>0){
                    pq.push(p1);
                }

                pq.push(p);
            }
        }
        
        return res;
    }
};
