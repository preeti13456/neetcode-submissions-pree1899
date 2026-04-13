class Solution {
public:
//State : Buying or selling 
// if buy -> i+1
// if selling -> i+2
//key ->(i,  buying/selling ) val=max_profit
//dp[i, buy] // maximum profit starting from ith day with state buy
int dfs(int i,int buy, vector<int>&prices, vector<vector<int>>&dp)
{
    //edge case is index goes out of bounds  or emty array so we can't make an y profits  
    if(i>=prices.size()) return 0;

//if i and buying pair has already computer if they ae already in our dp , associate profit already computed and return it 

    if(dp[i][buy]!=-1)
    return dp[i][buy];

    int profit = 0;

    //now the decision that we gonna make depend on are we buying or selling 
    //buy case
    if(buy)
    {
//buy or cooldown day
//profit when we are buying is we recursively calling dfs index i+1, stat will be not buying srtate right now
//if we bought we have to subtract the price , this will tell us how much max profit we can mke form remianing array start at not buy state
int buyStock = dfs(i+1, 0, prices, dp) - prices[i];
//we are same st buying state and we are not anything so we are sub or add anything
int cooldown = dfs(i+1, 1, prices, dp);
//cache dp and compute which of above teh two decison give us max profit
profit = max(buyStock, cooldown);
//cache soluton so if we recompute up above we just return instead of recursvely computingagain
    }
    //sell case
    else
    {
            //handle sell case index by 2 increase as take cooldown day inso consideration as well negate value of boolean , buying state to true
            //we want to add price as we sold we made soem money 
            int sellStock = dfs(i+2, 1, prices, dp)+prices[i];
            //cooldown is just skipping teh day s it will be same
            int cooldown = dfs(i+1, 0, prices, dp);
//cache dp and compute which of above teh two decison give us max profit
            profit = max(sellStock, cooldown);
    }
    return dp[i][buy] = profit;
}
    int maxProfit(vector<int>& prices) {
        //we have to kee the track are we buying or selling 
        //and we can't sell before buying
        //so first we have to buy the stock 
        //1. decision in buy 
        //total profit if we buy initially -1
//[1,2,3,0,2]
        //              ___0____
        //             /        \
        //         (-1)Buy      Cooldown (0)
        //         /      \
        //.    (+2)Sell.  cooldown(-1)
        //.     Profit(1)

        //Dp using caching
        //(i(index)->n different value, buy/sell(boolean: 2(n))
        //O(n)

        int n = prices.size();
        //initial buying state is true i.e 1
        //index we start at from 0 in price arrya 
        vector<vector<int>>dp(n, vector<int>(2, -1));

        return dfs(0, 1, prices, dp);
    }
};
