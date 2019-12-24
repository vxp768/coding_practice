/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        if(nums.size()==0)
            return result;
        for(int i=0; i<nums.size(); i++){
            if(nums[abs(nums[i])-1] < 0){
                result.push_back(abs(nums[i]));
            } else {
                nums[abs(nums[i])-1] = -1* nums[abs(nums[i])-1];
            }
        }
        return result;
    }
};

