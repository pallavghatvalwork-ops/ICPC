 /*
 
 Given an array arr[]. Rotate the array to the left 
 (counter-clockwise direction) by d steps, where d is a positive integer.
  Do the mentioned change in the array in place.

Note: Consider the array as circular.
 
 
 
 */
 #O(n^2)
 void rotateArr(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
        while(d--){
            int temp=arr[0];
            for(int i=0;i<n;i++){
                arr[i]=arr[i+1];
            }
            
            arr[n-1]=temp;
        }
        
    }
};




#O(n)

class Solution {
  public:
  
    void rev_arr(vector<int>& arr,int start,int end){
        
        while(start<end){
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        // code here
        int n=arr.size();
        d=d%n;
        rev_arr(arr,0,d-1);
        rev_arr(arr,d,n-1);
        rev_arr(arr,0,n-1);
    }
};
