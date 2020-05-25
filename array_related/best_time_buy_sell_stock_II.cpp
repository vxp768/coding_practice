/* Best Time to Buy and Sell Stock with Cooldown
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
 * (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

        You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).    
        After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)
            return 0;
        vector<int> B(prices.size(), 0); //BUY          maximum profit when sequence of events ends with Buy
        vector<int> S(prices.size(), 0); //SELL         maximum profit when sequence of events ends with Sell
        vector<int> R(prices.size(), 0); //REST         maximum profit when sequence of events ends with Rest
        
        //Consider starting with zero money and then for buy reduce the price
        //for sell add price...this will result in storing the diff in S[]
        B[0] = -prices[0];
        
        //maintain all the states B/S/R for each index
        for(int i=1; i<prices.size(); i++) {
            //if price is lower then change the purchase price
            B[i] = max(B[i-1], R[i-1]-prices[i]);
            //if price is higher then update the sell price
            S[i] = max(S[i-1], B[i-1]+prices[i]);
            //if there is no purchase at i, R[i] will be higher than B[i]
            //since if we buy then we subtract prices[i] from the money that was there
            R[i] = max(R[i-1], S[i-1]);
        }
        return S[prices.size()-1];
    }
};

//BUY SELL....with transaction fee
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size()==0)
            return 0;
        vector<int> B(prices.size(), 0);
        vector<int> S(prices.size(), 0);
        B[0] = -prices[0];
       
        for(int i=1; i<prices.size(); i++) {
            B[i] = max(B[i-1], S[i-1]-prices[i]);
            S[i] = max(S[i-1], prices[i]+B[i-1]-fee);
        }
        return S[prices.size()-1];
    }
};

//BUY SELL with max two transactions
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        vector<int> B1(prices.size(), 0);
        vector<int> S1(prices.size(), 0);
        vector<int> B2(prices.size(), 0);
        vector<int> S2(prices.size(), 0);
        B1[0] = -prices[0];
        B2[0] = -prices[0];
        for(int i=1; i<prices.size(); i++) {
            //first transaction will always start with 0 cash
            B1[i]  = max(B1[i-1], -prices[i]);
            S1[i]  = max(S1[i-1], B1[i-1]+prices[i]);
            //for second transaction need to add profit from first transaction
            B2[i]  = max(B2[i-1], S1[i-1]-prices[i]);
            S2[i]  = max(S2[i-1], B2[i-1]+prices[i]);
        }
        return S2[prices.size()-1];
    }
};

//BUY SELL with K transactions
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0 || prices.size()==0)
            return 0;
        vector<vector<int>> B(k, vector<int>(prices.size(), 0));
        vector<vector<int>> S(k, vector<int>(prices.size(), 0));
        for (int j=0; j<k; j++){
            B[j][0] = -prices[0];
        }
        for(int i=1; i<prices.size(); i++){
            B[0][i] = max(B[0][i-1], -prices[i]);
            S[0][i] = max(S[0][i-1], B[0][i-1]+prices[i]);
            for(int j=1; j<k; j++){
                B[j][i] = max(B[j][i-1], S[j-1][i-1]-prices[i]);
                S[j][i] = max(S[j][i-1], B[j][i-1]+prices[i]);
            }
        }
        return S[k-1][prices.size()-1];
    }
};
//Space optimized K transactions
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0 || prices.size()==0)
            return 0;
        int profit=0, x;
        if(k > (prices.size()/2)){
            //k is like infinity from prices length point of view
            int minPrice = prices[0];
            for(x=1; x<prices.size(); x++){
                if(prices[x] < prices[x-1]){
                    profit += prices[x-1]-minPrice;
                    minPrice = prices[x];
                }
            }
            profit += prices[x-1]-minPrice;
            return profit;
        } 
        vector<int> B(k, 0);
        vector<int> S(k, 0);
        for (int j=0; j<k; j++){
            B[j] = -prices[0];
        }
        for(int i=1; i<prices.size(); i++){
            S[0] = max(S[0], B[0]+prices[i]);
            B[0] = max(B[0], -prices[i]);
            for(int j=1; j<k; j++){
                S[j] = max(S[j], B[j]+prices[i]);
                B[j] = max(B[j], S[j-1]-prices[i]);
            }
        }
        return S[k-1];
    }
};