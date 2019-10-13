/*
Need to find count of subarray not sub sequence
Cannot sort array
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int size = nums.size();
        if (size <= 0) return 0;
        if (k <= 1) return 0;
        
        int count=0;
        int prod = 1;
        
        int left=0;
        for (int right=0; right<size; right++){
            prod = prod*nums[right];
            while (prod>= k){
                prod = prod/nums[left];
                left++;
            }
            count += right - left + 1; //this gives number of pairs
        }
        return count;
    }
};