class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int sum1 = 0;
      int n = nums.size();
      //[2,3,5,6]
      for(int i=0; i<n; i++)
      {
        sum1+=nums[i]; //16
      }  
int sum2 = (n*(n+1))/2;//10
return sum2-sum1;
    }
};
