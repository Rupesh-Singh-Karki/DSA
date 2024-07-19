class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        for(int i=0; i<nums.size(); i++){
            temp[(i+k)%nums.size()] = nums[i]; //kisi ka bhi % karne sai woh 0-n-1 ki range mai ayga (if done for n)
        } // % karne sai uska index agaya on rotation = cyclic way mai kth position par shift kardega
        nums=temp; //copy temp in nums
        
    }
};