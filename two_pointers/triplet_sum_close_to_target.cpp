//no duplicates in array
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left, right;
        int closest_diff=INT_MAX;
        int result;
        for (int i=0; i<nums.size(); i++) {
            left = i+1; right=nums.size()-1;
            int sum;
            while(left<right) {
                //this problem assumes no duplicate...else need to get rid of them
                sum = nums[i] + nums[left]+nums[right];
                if(abs(sum-target)<closest_diff) {
                    closest_diff = abs(sum-target);
                    result = sum;
                }
                if(sum<target) {
                    left++;
                } else if (sum>target) {
                    right--;
                } else {
                    return sum;
                }
            }
        }
        return result;
    }
};