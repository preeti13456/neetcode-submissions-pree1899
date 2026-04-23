class Solution {
public:
    bool isMatch(string s, string p) {
//         Input: s = "xyz", p = ".*z"

// Output: true
        int m = s.size();//3
        int n = p.size(); //3
        //state is true or false 
        vector<vector<bool>>dp(m+1, vector<bool>(n+1, false));

        dp[0][0] = true;
        for(int i=1; i<=m; i++)
        {
            dp[i][0] = false;
        }
        for(int j=2; j<=n; j++)
        {
          //  '*' Matches zero or more of the preceding element.

            if(p[j-1]=='*')
            {
                dp[0][j] = dp[0][j-2];
            }
        }
        auto match = [&](char a, char b)
        {
            return b=='.'||a==b;
        };
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(p[j-1]!='*')
                {
                    dp[i][j] = dp[i-1][j-1] && match(s[i-1], p[j-1]);
                }
                else
                {
                    dp[i][j] = dp[i][j-2];
                    if(j>=2 && match(s[i-1], p[j-2]))
                    {
                        dp[i][j] = dp[i][j]||dp[i-1][j];
                    }
                }
            }
        }
            return dp[m][n];

        
    }
};
