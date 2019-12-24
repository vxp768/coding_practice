/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction 
(i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Note that you cannot sell a stock before you buy one.

Input: [7,1,5,3,6,4]
Output: 5
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int i=0; i<prices.size(); i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            } else if (prices[i] - min_price > max_profit) {
                max_profit = prices[i] - min_price;
            }
        }
        return max_profit;
    }
};

// MULTIPLE TRANSACTIONS ALLOWED
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        if(prices.size()==0)
            return 0;
        int min_price = prices[0];
        for(int i=1; i < prices.size(); i++){
            if(prices[i] < prices[i-1]){
                profit += prices[i-1] - min_price;
                min_price = prices[i];
            }
        }
        profit += prices[prices.size()-1] - min_price;   //takes care of last increasing seq
        return profit;
    }
};

//USE valley peak concept to calculate profit
int maxProfit(vector<int>& prices) {
        int i=1;
        int profit = 0;
        int valley = 0;
        int peak   = 0;
        
        while (i< prices.size()) {
            while(i<prices.size() && prices[i] <= prices[i-1])
                i++;
            valley = prices[i-1];
            while(i<prices.size() && prices[i] >= prices[i-1])
                i++;
            peak = prices[i-1];
            profit += peak - valley;
            
        }
        return profit;
}


//  OR better use of peak and valley
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if (prices.size() == 0){
            return 0;
        }
        for (int i=0; i< prices.size() - 1 ; i++) {
            if (prices[i] < prices[i+1]){
                profit += prices[i+1] - prices[i];
            }
        }
        return profit;
    }
};
