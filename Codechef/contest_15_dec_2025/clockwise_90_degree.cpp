#given n*n matrix rotate it clock wise 90 degree 

void rotateClockwise(vector<vector<int> > &matrix) {
    // write your codde here 
    
    
    for(int i=0;i<matrix.size();i++){
        for(int j=i+1;j<matrix.size();j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    
    
    for(int i=0;i<matrix.size();i++){
        int l=0,r=matrix.size()-1;
        while(l<r){
            swap(matrix[i][l],matrix[i][r]);
            l++;
            r--;
        }
    }
}

