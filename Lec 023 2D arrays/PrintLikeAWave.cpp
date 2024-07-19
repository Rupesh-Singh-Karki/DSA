//wave mtlb pehle downward print phir waha sai next column mai upward.

#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for(int i=0; i<mCols; i++){
        if(i&1){  //odd number index mai wave uppar ja raha hai
            for(int j=nRows-1 ;j>=0 ; j--){
                ans.push_back(arr[j][i]);
            }

        }
        else{
            for(int j=0 ;j<nRows ; j++){
                ans.push_back(arr[j][i]);
            }
        }
    }
    return ans;
}