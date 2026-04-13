class Solution {
public:
    vector<int> countBits(int n) {
        //we are using the dp here as we use the previous res
        //to compute new result here 
        //what are significant bits ?
        //1, 2, 4, 8, 16
        //this is how many we are trying to compute
        vector<int>dp(n+1);

        //n=8
        //1, 2,3,4,5,6,7,8

//highest power of 2
        int offset = 1;

        for(int i=1; i<=n; i++)
        {
            //as we myltiply our offset by 2 it will give us the value we are at
                if(offset*2==i)
                offset = i;

                //no. of bits and 1 = dp[i]
                //dp[i-offset]
                dp[i] = 1+dp[i-offset];
        }
        return dp;

    }
};
