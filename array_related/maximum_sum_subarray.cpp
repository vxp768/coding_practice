/*
Given an integer array nums, find the contiguous subarray
(containing at least one number) which has the largest sum and return its sum.

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
*/
/*  Dynamic programming
 *  maxSubArray(A, i) = (maxSubArray(A, i - 1) > 0 ? maxSubArray(A, i - 1):0)    +   A[i];
 */
int maxSubArray(vector<int> &nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int max_sum = dp[0];
    for(int i=1; i<nums.size(); i++){
        dp[i] = max(dp[i-1]+nums[i], nums[i]);
        max_sum = max(max_sum, dp[i]);
    }
    return max_sum;
}
//Save on space...only dp[i-1] needs to be stored
int maxSubArray(vector<int> &nums) {
        int sum = nums[0];
        int max_sum = sum;
        for(int i=1; i<nums.size(); i++){
            sum = max(sum + nums[i], nums[i]);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
}

//Use divide and conquer


/* Gives indexes of subarray */
int maxSubArray(int* nums, int numsSize) {
  int start = 0, end = 0, s = 0;
 int max_so_far = nums[0],  max_subarr = nums[0];

 for (int k=1; k<numsSize; k++) {
     //reset the start index only if sum becomes less than new number
     if (max_subarr + nums[k] <= nums[k]){
         max_subarr = nums[k];
         s = k;
     } else {
         max_subarr = max_subarr + nums[k];
     }
     if (max_subarr > max_so_far) {
        max_so_far = max_subarr;
        start = s;
        end = k;
     }
 }
   return max_so_far; 
}