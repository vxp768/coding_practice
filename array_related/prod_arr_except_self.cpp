/*
 * Product of array except self
 */ 
 //Using two arrays: one fo rleft pass and another for right pass
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left_pass(nums.size(), 1);
        vector<int> right_pass(nums.size(), 1);
        vector<int> result(nums.size(), 1);
       
        int prev = 1;
        for(int i=0; i<nums.size(); i++){
            left_pass[i] = prev;
            prev *= nums[i];
        }
        prev=1;
        for(int i=nums.size()-1; i>=0; i--){
            right_pass[i] = prev;
            prev *= nums[i];
        }
        for(int i=0; i<nums.size(); i++){
            result[i] = left_pass[i]*right_pass[i];
        } 
        return result;
    }
};

//Using O(1) space...output array does not count towards storage complexity
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> right_pass(nums.size(), 1);
        vector<int> result(nums.size(), 1);
       
        int prev = 1;
        for(int i=0; i<nums.size(); i++){
            result[i] = prev;
            prev *= nums[i];
        }
        prev=1;
        for(int i=nums.size()-1; i>=0; i--){
            right_pass[i] = prev;
            result[i]     = result[i]*right_pass[i];
            prev         *= nums[i];
        }
        return result;
    }
};