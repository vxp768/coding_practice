class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
        //vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        return LCS(text1, text2);
    }
    /* Memoization exceeds time limit
    int LCS(string s1, string s2, int m, int n, vector<vector<int>> &dp) {
        if(m == 0 || n==0){
            return 0;
        }
        if(dp[m-1][n-1] !=-1)
            return dp[m-1][n-1];
        
        if(s1[m-1]==s2[n-1]) {
            dp[m-1][n-1] = 1+LCS(s1, s2, m-1, n-1, dp);
        } else {
            dp[m-1][n-1] = max(LCS(s1, s2, m, n-1, dp), LCS(s1, s2, m-1, n, dp));
        }
        return dp[m-1][n-1];
    }*/
    
    //Tabulation
    //int LCS(string s1, string s2, vector<vector<int>>& dp) {
    int LCS(string s1, string s2) {
        vector<vector<int>> dp(2, vector<int>(s2.size()+1, 0));
        int pre=0, cur=1;
        for(int i=1; i<=s1.size(); i++){
            for(int j=1; j<=s2.size(); j++){
                if(s1[i-1] == s2[j-1]) {
                    dp[cur][j] = 1+dp[pre][j-1];
                } else {
                    dp[cur][j] = max(dp[cur][j-1], dp[pre][j]);
                }
            }
            swap(pre, cur);
        }
        return dp[pre][s2.size()];
    }
    
};