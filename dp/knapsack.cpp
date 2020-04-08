/* 0-1 Knapsack */
// Returns the maximum value that can be put in a knapsack of capacity=W
int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 
  
   for (i = 0; i <= n; i++) { 
       for (w = 0; w <= W; w++) { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
}

/* Knapsack with repetion of items allowed */
int knapsack_repeat(int W, int wt[], int val[], n)
{
    vector<int> dp(W+1, 0);
    for (int w=1; w<=W; w++) {
        //try all objects for weight 'w'
        for (int i=0; i<n; i++) {
            if(wt[i] <= w){
                dp[w] = max(dp[w], dp[w-wt[i]]+val[i]);
            }
        }
    }
    return dp[W];
}

//  Minimum coins for change
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        int max_am = amount+1;
        vector<int> num_coins(amount+1, max_am);
        num_coins[0] = 0;
        for(int a=1; a<=amount; a++){
            //try all coins
            for(int i=0; i<coins.size(); i++){
                if(coins[i] <= a) {
                    num_coins[a] = min(num_coins[a], 1+num_coins[a-coins[i]]);
                }
            }
        }
        return num_coins[amount]>amount?-1:num_coins[amount];
    }
};



/*Similar code for subset-sum = K */


