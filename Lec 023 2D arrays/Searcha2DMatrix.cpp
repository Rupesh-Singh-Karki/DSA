#include<iostream>
#include<vector>

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(); //gives you the number of rows.
        int c=matrix[0].size(); //gives you the number of columns based on the assumption that all rows have the same number of columns.

        int start=0;
        int end=r*c-1;
        int mid=start+(end-start)/2;
        
        while(start<=end){
            int element=matrix[mid/c][mid%c]; //here c=4 so eg if mid=6 then mid/c=1 and mid%c=2 .

            if(element==target){
                return 1;
            }
            if(element<target){
                start=mid+1;                
            }
            else{
                end=mid-1;
            }
            mid=start+(end-start)/2;
        }
        
        return 0;
    }
};