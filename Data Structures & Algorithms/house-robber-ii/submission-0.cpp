class Solution {
public:
int robLinear(vector<int>&nums, int l, int r)

{
    //Robbing the first house will be our base case 
        int n = nums.size();
        // int base = nums[0];
        //we only need to compute up until that point max rob money we have done to take decison 
        //2,7,9,3,1
        int rob1 = 0, rob2 = 0;
        //as we iterate through each and every house 
        for(int i=l; i<=r; i++)
        {
            //[rob1, rob2, n, n+1]
            //rob1+num is the gap between current house and prev house
            //rob2 is current house
            int curr = max(rob2, rob1+nums[i]);
            rob1 = rob2;
            rob2 = curr;
        }

        return rob2;
}
    int rob(vector<int>& nums) {
        //last value will be adjacent to first value 
int n = nums.size();
//skip first house 
if(n==1) return nums[0];
return max(
    //skipping the first house
    robLinear(nums, 0, n-2),
    //skipping the last house
    robLinear(nums, 1, n-1 )

);
        
    }
};
