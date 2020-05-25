/* row of n houses, each house can be painted with one of the k colors.
 * Find min cost to paint the houses, no two house can have same color.
 *  Input: [[1,5,3],[2,9,4]]
    Output: 5
    Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
             Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5. 
 * 
 * 
 */
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n,k;
        n = costs.size();
        if (n == 0) {
            return 0;
        }
        k = costs[0].size();
        vector<vector<int>> dp(n, vector<int>(k, INT_MAX));
        for(int i=0; i<k; i++){
            dp[n-1][i] = costs[n-1][i]; //init the last house
        }
        for(int h=n-2; h>=0; h--){
            for(int c=0; c<k; c++){
                for(int n_c=0; n_c<k; n_c++){
                    if(c != n_c){ //avoiding two houses with same color
                       dp[h][c] = min(dp[h][c], costs[h][c]+dp[h+1][n_c]); 
                    }
                }
            }
        }
        int min_cost = INT_MAX;
        for(int i=0; i<k; i++) {
            min_cost = min(min_cost, dp[0][i]);
        }
        return min_cost;
    }   
};


//Memoization for 3 color problem
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<int> res;
        vector<vector<int>> memo(costs.size(), vector<int>(3, INT_MAX));
        return rec(costs, res, -1, 0, memo);
    }
    int rec (vector<vector<int>>& costs, vector<int> &res, int prev_col, int idx, vector<vector<int>> &memo) {
        int cost_col = 0;
        int min_cost = INT_MAX;
        if(idx==costs.size()){
            return 0;
        }
        for(int i=0; i<3; i++) {
            if(i == prev_col)
                continue;
            if(memo[idx][i] == INT_MAX){
                cost_col = rec(costs, res, i, idx+1, memo);
                memo[idx][i] = cost_col + costs[idx][i];
            }
            min_cost = min(min_cost, memo[idx][i]);
        }
        return min_cost;
    }
};