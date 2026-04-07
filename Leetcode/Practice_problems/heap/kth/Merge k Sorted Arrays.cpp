/*

Merge k Sorted Arrays
Difficulty: MediumAccuracy: 67.25%Submissions: 129K+Points: 4Average Time: 45m
You are given a 2D matrix mat[][] of size n x m. Each row in the matrix is sorted in non-decreasing order. Your task is to merge all the rows and return a single sorted array that contains all the elements of the matrix.

Examples :

Input: mat[][] = [[1, 3, 5, 7],
                [2, 4, 6, 8], 
                [0, 9, 10, 11]]
Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
Explanation: Merging all elements from the 3 sorted arrays and sorting them results in: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11].
Input: mat[][] = [[1, 2, 3, 4], 
                [2, 2, 3, 4],
                [5, 5, 6, 6],
                [7, 8, 9, 9]]
Output: [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9] 
Explanation: Merging all elements from the 4 sorted arrays and sorting them results in:[1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9]
Constraints:
1 = n * m = 105
1 = mat[i][j] = 106

*/

class Solution {
  public:
  
    class Node{
        public:
        int value;
        int row;
        int col;
        
        
        Node(int v,int r,int c){
            value=v;
            row=r;
            col=c;
        }
    };
    
    struct cmp{
        bool operator() (const Node&a,const Node&b){
            return a.value > b.value;
        } 
    };
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
       int n=mat.size();
       int m=mat[0].size();
       
       priority_queue<Node,vector<Node>,cmp>pq;
       
       for(int i=0;i<n;i++){
           pq.push({mat[i][0],i,0});
       }
       
       vector<int>res;
       
       while(!pq.empty()){
           Node n=pq.top();
           pq.pop();
           
           int v=n.value;
           int row=n.row;
           int col=n.col;
           res.push_back(v);
           
           if(col<(m-1)){
               pq.push({mat[row][col+1],row,col+1});
           }
       }
       
       return res;
    }
};
