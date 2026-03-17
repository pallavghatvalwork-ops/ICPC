/*

1552. Magnetic Force Between Two Balls
Solved
Medium
Topics
premium lock icon
Companies
Hint
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.

 

Example 1:


Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
Example 2:

Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.
 

Constraints:

n == position.length
2 <= n <= 105
1 <= position[i] <= 109
All integers in position are distinct.
2 <= m <= position.length

*/

class Solution {
public:

    bool func(vector<int>&position,int n,int k,int guess){
        int balls=1;
        int pos=position[0];
        
        for(int i=1;i<n;i++){
            int dist=position[i]-pos;
            
            if(dist<guess){
                continue;
            }
            
            balls++;
            pos=position[i];
        }
        
        if(balls>=k){
            return true;
        }else{
            return false;
        }
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=1,high=position[n-1]-position[0];
        int res=-1;
        
        while(low<=high){
            int guess=low+(high-low)/2;
            
            if(func(position,n,m,guess)){
                res=guess;
                low=guess+1;
            }else{
                high=guess-1;
            }
        }
        
        return res;
        
    }
};


