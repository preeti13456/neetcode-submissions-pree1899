class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        //-4 , -1, -1, 0, 1, 2
        sort(nums.begin(), nums.end());
        int n = nums.size();
        //duplicate will be neighbour
        for(int i=0; i<n-2; i++)
        {
            //-1 skip duplicate ek baar hi counter krenge 
            if(i>0 && nums[i]==nums[i-1]) continue;
//two pointer 
            int l = i+1;
            int r = n-1;
            while(l<r)
            {
                int sum = nums[i]+nums[l]+nums[r];
                if(sum==0)
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    //first and second no. if same will skip it 

                    //skip duplicates

                    while(l<r && nums[l]==nums[l-1])l++;

                    while(l<r && nums[r]==nums[r+1])r--;
                }
                else if(sum<0)
                {
                    l++; //move left pointer to increase sum
                }
                else
                {
                    r--; //move right pointer decrease sum
                }

            }
        }
        return res;
    }
};
