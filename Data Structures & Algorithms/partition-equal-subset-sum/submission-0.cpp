class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%2==1) return false;
        sum/=2;
        //5,6,7,11

vector<bool>dp(sum+1, false);
dp[0] = true;
for(int num : nums)

    for(int i=sum-num; i>=0; i--)
    if(dp[i])dp[i+num] = true;

    return dp[sum];

    }
};
