/*



231. Power of Two
Solved
Easy
Topics
premium lock icon
Companies
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
 

Constraints:

-231 <= n <= 231 - 1
 

Follow up: Could you solve it without loops/recursion?


*/



class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n==1){
            return true;
        }

        if(n<=0||n%2!=0){
            return false;
        }

        int low=0,high=30;
        while(low<=high){

            int mid=low+(high-low)/2;
            int res=(int)pow(2,mid);
            if(res==n){
                return true;
            }

            if(res>n){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        return false;
    }
};
