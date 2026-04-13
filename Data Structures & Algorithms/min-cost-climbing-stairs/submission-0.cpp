class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       
        int n = cost.size();
        //bottom up approach 
        //[1,2,3]
        // dp[0] = 1
        // dp[1] = 2
        // dp[2] = 3+min(1,2)=4

    vector<int>dp(n);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i=2 ;i<n;i++)
    {
        dp[i] = cost[i]+min(dp[i-1], dp[i-2]);
    }
return min(dp[n-1], dp[n-2]);
    }
};
