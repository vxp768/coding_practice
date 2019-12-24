//RECURSIVE
// Returns length of function for longest common   
// substring of X[0..m-1] and Y[0..n-1]  
int lcs(int i, int j, int count)  
{ 
      
    if (i == 0 || j == 0) 
        return count; 
          
    if (X[i-1] == Y[j-1]) { 
        count = lcs(i - 1, j - 1, count + 1); 
    } 
        count = max(count, max(lcs( i, j - 1, 0), lcs( i - 1, j, 0))); 
    return count; 
} 

//TABULATION
int LCSubStr(char *X, char *Y, int m, int n) 
{  
    int dp[m+1][n+1]; 
    int result = 0;  // To store length of the  
                     // longest common substring 
  
    /* Following steps build dp[m+1][n+1] table in 
        bottom up fashion. */
    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        { 
            // The first row and first column  entries have no logical meaning,
            // they are used only for simplicity  of program 
            if (i == 0 || j == 0) {
                dp[i][j] = 0; 
            } else if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1; 
                result = max(result, dp[i][j]); 
            } else {
                dp[i][j] = 0; 
            }
        } 
    } 
    return result; 
} 

