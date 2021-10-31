/* Given an array of integers and a number k, find maximum sum of a subarray of size k.
   Input  : arr[] = {100, 200, 300, 400}
         k = 2
   Output : 700
*/

// Returns maximum sum in a subarray of size k. 
int maxSum(int arr[], int n, int k) 
{ 
    // k must be greater 
    if (n < k) { 
       cout << "Invalid"; 
       return -1; 
    } 
  
    // Compute sum of first window of size k 
    int res = 0; 
    for (int i=0; i<k; i++) 
       res += arr[i]; 
  
    // Compute sums of remaining windows by removing first element of previous 
    // window and adding last element of current window. 
    int curr_sum = res; 
    for (int i=k; i<n; i++) { 
       curr_sum += arr[i] - arr[i-k]; 
       res = max(res, curr_sum); 
    } 
    return res; 
} 

/*
 * Given an integer array nums, find the contiguous subarray (containing at least one number) 
 * which has the largest sum and return its sum.
 * Window is not defined
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int max_sum = sum;
        for(int i=1; i<nums.size(); i++){
            sum = max(sum + nums[i], nums[i]);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};