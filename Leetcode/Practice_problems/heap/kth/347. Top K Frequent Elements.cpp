/*

347. Top K Frequent Elements
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.
 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/


class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
            if(a.first!=b.first){
                return a.first > b.first;
            }

            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;

        unordered_map<int,int>f;

        for(int i=0;i<n;i++){
            f[nums[i]]++;
        }

        for(auto i:f){
            int ele=i.first;
            int freq=i.second;

            pair<int,int>curr={freq,ele};

            if(pq.size()<k){
                pq.push(curr);
                continue;
            }

            if(curr.first < pq.top().first){
                continue;
            }

            pq.pop();
            pq.push(curr);
        }

        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
