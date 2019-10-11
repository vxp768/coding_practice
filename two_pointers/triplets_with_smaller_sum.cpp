/*
Given an array of n integers nums and a target, 
 find the number of index triplets i, j, k with 0 <= i < j < k < n 
 that satisfy the condition nums[i] + nums[j] + nums[k] < target.
*/
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int count=0;
        int left, right;
        int sum;
        if(nums.size()<3)
            return 0;
        for(int i=0; i<nums.size()-2; i++){
            int two_tgt = target - nums[i];
            
            left = i+1; right = nums.size()-1;
            int two_sum;
            
            while(left<right) {
                two_sum = nums[left]+nums[right];
                
                if(two_sum < two_tgt) {
                    //add number of pair between right and left whose sum will be less than two_tgt
                    //imagine left index fixed and right keep decreasing...so sum will keep getting lesser
                    count += right-left; 
                    left++;
                } else {
                    right--;
                }
            }
            
        }
        return count;
    }
};