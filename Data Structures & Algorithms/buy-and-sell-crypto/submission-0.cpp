class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //max profit we get is if we set at a particular point which is minum value
        //left pointer on day 1
        //right pointer on day 2
       // left is always less then right
       // if we sense that right is small we make it left and start from thee
       //tc: O(n) because we are only scanning whole array one time
       //sc: O(1) AS WE ARE doing comparison in lace no extra space used
       int l =0 ; //default case
       int r = 1;
       //we keep on iteracting teh right ointer until it reach end of prices
       int maxProfit = 0;

       while(r<prices.size())
       {
        //Profitable?
        if(prices[l]<prices[r])
        {
            int profit = prices[r]-prices[l];
            maxProfit = max(maxProfit, profit);
        }
        //not profitable 
        else
        {
                l=r;
        }
        r++;
       }
       return maxProfit;
    }
};
