class Solution {
public:
    int maxSubArray(vector<int>& nums) {
//         Input: nums = [2,-3,4,-2,2,1,-1,4]

// Output: 8
int ans = INT_MIN;
int curr_min = 0;
int sum = 0;
for(int num : nums)
{
    //sum = 2-3 = -1+4 = 3-2=1+2 = 3+1 = 4-1=3+4 = 7
sum+=num;
//ans = max(0, 2)
//ans = 2
//ans = max(2, -1-2)
//ans = 2
//ans = max(2, 3+1)
//ans = 4
//
ans = max(ans, sum-curr_min);

//curr_min = -1
//curr_min = -1
//curr_min = -1

curr_min = min(curr_min, sum);
}
return ans;
    }
};
