/*

692. Top K Frequent Words
Solved
Medium
Topics
premium lock icon
Companies
Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 

Constraints:

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]
 

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?

*/


class Solution {
public:
    struct cmp{
        bool operator()(pair<int,string>&a,pair<int,string>&b){
            if(a.first!=b.first){
                return a.first > b.first;
            }

            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();

        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;

        unordered_map<string,int>f;

        for(int i=0;i<n;i++){
            f[words[i]]++;
        }

        for(auto i:f){
            string ele=i.first;
            int freq=i.second;

            pair<int,string>curr={freq,ele};

            if(pq.size()<k){
                pq.push(curr);
                continue;
            }

            if(curr.first < pq.top().first ||(curr.first == pq.top().first && curr.second > pq.top().second)){
                continue;
            }

            pq.pop();
            pq.push(curr);
        }

        vector<string>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
