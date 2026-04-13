class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //buy and sell as many times as posible 
        //  
        //  7.
        //   \          6.
        //    \    _5. / \
// price//     \  /  |/   4.
       //       \/   3.
        //     |  
        //     1.  
        // // // // // // // // // // // 
                //Day

                //from 7 f we buy it will keep on declining till 1 which is huge losee but if we buy at 1 and sell at 5 there will be profile as prices are going up 
                //from 1 it will be going to local maxim, stock are gonna dive so we rebuy at 3
                //sold at 5 at buy at 1 , again we can rebuy at 3 and sold at 6 
                //5-1 = 4 as now we ave sold at 5 so we have to rebuy again at 3 but there is a decline from 5 -> 3 as stock goes doen but we can not saw any loss from thsi decline 
            //as we are not holding any more 
            //but we can at 3 out stock is gonna go up so definitely we buy at 3 and sell at 6 
            //from 6->4 we can see that the stocks gonna go down so there is decline 
            //hence we sell at 6 only as we bought at 3
            //1. profit was from 5-1 = 4
            //2. profit was from 6-3 = 3
            //Total profit = 4+3 = 7

            //but here we are only add teh where there is increase of stock price to profit
            //stcok is increase value we are adding differentials in max total profit 
            //as we are only gon toeach and every value i=once and compare it with teh next value O(n)
            //we don't use any extra sapce so space is O(1)
            int n = prices.size();
            int profit = 0;
            for(int i=1; i<n; i++)
            {
                if(prices[i]>prices[i-1]){
                    profit += prices[i]-prices[i-1];
                }
            }
            return profit;
    }
};