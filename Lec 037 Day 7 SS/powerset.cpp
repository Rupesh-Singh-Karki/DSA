#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>>& ans,vector<int> output,int index,vector<int> nums ){
    //base case
    if(index>=nums.size()){
        ans.push_back(output); //yaha hum end stage par ayenge to saare output array kai element ko
        return;                //ans mai stor kara lenge
    }

    //exlude
    solve(ans,output,index+1,nums);  //yaha exclude krna hai toh bas i+1 kardiya

    //include
    int element = nums[index];  //yaha jispar index ai use include krna hai toh elemnt ki valuee leli
    output.push_back(element);  //yah use ans mai push krdiya
    solve(ans,output,index+1,nums);

}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve(ans,output,index,nums);
    return ans;
        
}
