# Returns a single integer representing the maximum number of consecutive 1 s in the array.


#include<iostream>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    //write code here...
    int c=0,max_c=0;
    for(int i=0;i<nums.size();i++){
        
        if(nums[i]==1){
            c++;
            max_c=max(max_c,c);
        }else{
            c=0;
        }
    }
    
    return max_c;
    
}

