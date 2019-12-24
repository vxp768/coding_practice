/* Partition array in two half of equal sum
 * 
 * Same as finding subset with some target sum
 */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int size = nums.size();
        if(size<2) return false;
        
        for(int i=0; i<size; i++) {
            sum+=nums[i];
        }
        if(sum%2 != 0)
            return false;
        sum = sum/2;
        bool dp[size+1][sum+1];
        dp[0][0] = true;
        for(int i=1; i<=size; i++){
            dp[i][0] = true;  //sum==0 for s
        }
        for(int j=1; j<=sum; j++){
            dp[0][j] = false;
        }
        //0-1 knapsack solution
        for(int i=1; i<=size; i++) {
            for(int s=1; s<=sum; s++) {
                if (s>=nums[i-1]) {
                    dp[i][s] = dp[i-1][s-nums[i-1]] || dp[i-1][s];    
                } else {
                    dp[i][s] = dp[i-1][s];   
                }
            }
        }
        return dp[size][sum];
    }
};