class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int max=0,sec_max=-1;
    
    for(int i=0;i<arr.size();i++){
        
        if(max<arr[i]){
            
             sec_max=max;
             max=arr[i];
        }else if(arr[i]<max && arr[i]>sec_max){
            
            sec_max=arr[i];
        }
    }
    
     return sec_max;
    }
};
