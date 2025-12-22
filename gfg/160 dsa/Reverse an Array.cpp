class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int j=arr.size()-1;
        
        for(int i=0;i<arr.size()/2;i++){
            
            swap(arr[i],arr[j]);
            j--;
        }
    }
};
