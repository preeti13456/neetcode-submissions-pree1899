class Solution {
public:
bool canSplit(vector<int>&nums, int k, long long maxSum)
{
    //current sum 
    long long current = 0;
    //cunt of subarryas we can create
    int subarrays = 1;
    for(int num : nums)
    {
        //we get current sum exceed teh maxsum it allowed to be it goes into it oen grouo 

        if(current+num > maxSum)
        {
            subarrays++;
            //we need num to br start in seperate subarrya don't want ti add it 
            current = num;
                if(subarrays>k) return false;
        }
        else{
            current+=num;
        }
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        //optimal solution 
        //maximum the result could be is the sum of iut array 
        //minimum the result could be maximum of input array 
//[7,2,5,10,8]
//l = max(sum) -> 10
long long left = *max_element(nums.begin(), nums.end());

//r total sumwe can get 
long long right = accumulate(nums.begin(), nums.end(), 0LL);
while(left < right)
{
    long long mid = left + (right-left)/2;
    if(canSplit(nums, k, mid))
    right = mid;
    else
    left = mid+1;

}

return left;
    }
};