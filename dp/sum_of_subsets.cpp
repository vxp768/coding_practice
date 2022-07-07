// Find the subset of array with sum equal to some target

//Brute Force       O(2^N)
class Solution {
    
public:
    bool subset_sum_exists(vector<int>& nums, int sum){
        return subset_sum(nums, sum, 0);
    }
    bool subset_sum(vector<int> nums, int sum, int idx) {
        if(sum==0)
            return true;
        if(idx==nums.size() || sum<0)
            return false;
    
        return(subset_sum(nums, sum-nums[idx], idx+1) ||           //including idx
                subset_sum(nums, sum, idx+1));                  //NOT including idx
    
    }
};

//Using DP tabular method
/*        SUM: 0  1  2  3  4  5  6  7  8  9
   NUM:0  0    T  F  F  F  F  F  F  F  F  F
       1  3    T  F  F  T  F  F  F  F  F  F
       2  34   T  F  F  T  F  F  F  F  F  F
       3  4    T  F  F  T  T  F  F  T  F  F
       4  12   T  F  F  T  T  F  F  T  F  F
       5  5    T  F  F  T  T  T  F  T  T  T
       6  2    T  F  T  T  T  T  T  T  T  T
nums[i-1]
  arr = {3, 34, 4, 12, 5, 2} sum = 9
*/
// O(sum*N) space:O(sum*N)
class Solution {
    
public:
    bool subset_sum_exists(vector<int>& nums, int sum){
        vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1,0));
        for(int i=0; i<=nums.size(); i++){
            dp[i][0] = true;
        }
        for(int i=1; i<=sum; i++) {
            dp[0][i] = false;
        }
        dp[0][0]=true;
        for(int i=1; i<=nums.size(); i++) {
            for(int n=1: n<=sum; n++) {
                if(n < nums[i-1]){
                    dp[i][n] = dp[i-1][n];
                } else {
                    dp[i][n] = dp[i-1][n] || dp[i-1][n-nums[i-1]];
                }
            }
        }
        return dp[nums.size()][sum];
    }
};