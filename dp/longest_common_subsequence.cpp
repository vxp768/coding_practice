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


/////////           PRINT     ALL      LCS
/* Returns set containing all LCS for X[0..m-1], Y[0..n-1] */
set<string> findLCS(string X, string Y, int m, int n) 
{ 
    // construct a set to store possible LCS 
    set<string> s; 
  
    // If we reaches end of either string, return 
    // a empty set 
    if (m == 0 || n == 0) 
    { 
        s.insert(""); 
        return s; 
    } 
  
    // If the last characters of X and Y are same 
    if (X[m - 1] == Y[n - 1]) 
    { 
        // recurse for X[0..m-2] and Y[0..n-2] in 
        // the matrix 
        set<string> tmp = findLCS(X, Y, m - 1, n - 1); 
  
        // append current character to all possible LCS 
        // of substring X[0..m-2] and Y[0..n-2]. 
        for (string str : tmp) 
            s.insert(str + X[m - 1]); 
    } 
  
    // If the last characters of X and Y are not same 
    else
    { 
        // If LCS can be constructed from top side of 
        // the matrix, recurse for X[0..m-2] and Y[0..n-1] 
        if (L[m - 1][n] >= L[m][n - 1]) 
            s = findLCS(X, Y, m - 1, n); 
  
        // If LCS can be constructed from left side of 
        // the matrix, recurse for X[0..m-1] and Y[0..n-2] 
        if (L[m][n - 1] >= L[m - 1][n]) 
        { 
            set<string> tmp = findLCS(X, Y, m, n - 1); 
  
            // merge two sets if L[m-1][n] == L[m][n-1] 
            // Note s will be empty if L[m-1][n] != L[m][n-1] 
            s.insert(tmp.begin(), tmp.end()); 
        } 
    } 
    return s; 
} 
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int LCS(string X, string Y, int m, int n) 
{ 
    // Build L[m+1][n+1] in bottom up fashion 
    for (int i = 0; i <= m; i++) 
    { 
        for (int j = 0; j <= n; j++) 
        { 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
            else if (X[i - 1] == Y[j - 1]) 
                L[i][j] = L[i - 1][j - 1] + 1; 
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
        } 
    } 
    return L[m][n]; 
}