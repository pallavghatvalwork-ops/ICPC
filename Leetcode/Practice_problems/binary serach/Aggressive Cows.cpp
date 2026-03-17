/*

Aggressive Cows
Difficulty: MediumAccuracy: 59.57%Submissions: 204K+Points: 4Average Time: 30m
You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples:

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows in this case is 3, which is the largest among all possible ways.
Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows in this case is 4, which is the largest among all possible ways.
Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: There are 6 stalls and only 5 cows, we try to place the cows such that the minimum distance between any two cows is as large as possible.
The minimum distance between cows in this case is 1, which is the largest among all possible ways.
Constraints:
2 = stalls.size() = 106
0 = stalls[i] = 108
2 = k = stalls.size()

*/


class Solution {
  public:
  
    bool func(vector<int>&stalls,int n,int k,int guess){
        int cows=1;
        int pos=stalls[0];
        
        for(int i=1;i<n;i++){
            int dist=stalls[i]-pos;
            
            if(dist<guess){
                continue;
            }
            
            cows++;
            pos=stalls[i];
        }
        
        if(cows>=k){
            return true;
        }else{
            return false;
        }
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int low=1,high=stalls[n-1]-stalls[0];
        int res=-1;
        
        while(low<=high){
            int guess=low+(high-low)/2;
            
            if(func(stalls,n,k,guess)){
                res=guess;
                low=guess+1;
            }else{
                high=guess-1;
            }
        }
        
        return res;
        
    }
};
