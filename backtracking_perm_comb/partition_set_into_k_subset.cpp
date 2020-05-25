/* Given two numbers n and k where n represents number of elements in a set,
   find number of ways to partition the set into k subsets.
Input: n = 3, k = 2
Output: 3
Explanation: Let the set be {1, 2, 3}, we can partition
             it into 2 subsets in following ways
             { {1,2}, {3}   },  
             { {1},   {2,3} },
             { {1,3}, {2}   }
// for adding n^th elem
S(n,k)  = k*S(n-1, k) + S(n-1, k-1) 

S(n-1, k):       //new elem '4' can be added to any one of the subset...K=2 ways to add in above case hence multiplied by K
                 e.g.: {{1,2,4}, {3}}   or {{1,2}, {3,4}}       === k ways
                       {{1,4},   {2,3}}  or {{1},   {2,3,4}}    === again k ways
S(n-1, k-1):     //new elem is added as new subset with single elem in it
                {{1,2,3}, {4}}
*/

// Count number of ways to partition a set into k subsets
// implement recursion:  S(n,k)  = k*S(n-1, k) + S(n-1, k-1)
//    BRUTE FORCE
int count_subset(int n, int k) { //n is num of elems and K is num of subsets
    if(n==0 || k==0)
        return 0;
    if(k>n)
        return 0;
    return k*count_subset(n-1, k) + count_subset(n-1, k-1);
}

// DP bottom up
int count_subset (int n, int k) {
    int dp[n+1][k+1];
    for (int i=0; i<=n; i++){
        dp[i][0]=0;
    }
    for (int i=0; i<=k; i==){
        dp[0][i]=0;
    }
    for (int i=1; i<=n; i++){
        for (int j=1; j<=k; j++){
            if(j==1 || i==j){
                dp[i][j] = 1;
            } else {
                dp[i][j] = j*dp[i-1][j] + dp[i-1][j-1];
            }
        }
    }
    return dp[n][k];
}


/********          NUMBER of WAYS to PARTITION a SET      ************/
//     k varies from 1 to K
int total_num_subset(int n, int k) {
    int result;
    for (int i=0; i<=k ;i++) {
        result += count_subset(n, i);
    }
    return result;
}