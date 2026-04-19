class Solution {
public:
void findSubset(vector<int>&nums, int start, vector<vector<int>>&ans, vector<int>&subset)
{
    ans.push_back(subset);
    if(start==nums.size())
    {
        return;
    }
    for(int i=start; i<nums.size(); i++)
    {
        if(i>start && nums[i]==nums[i-1])continue;
        subset.push_back(nums[i]);
        findSubset(nums, i+1, ans, subset);
        subset.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //approach :
        //1. sort array 
        //backtracking to build subssest incementally
        //at each recirsive call current subset added to resuly
        //backtrack by removing last elemnt before going for next possibility
        //[1,2,1]
        //1,2   1
        //1  2
        vector<vector<int>>ans;//[[1,2], [1], [1,1]]
        vector<int>subset; //[1,2], [1], [1,1], etc
        //sorting helps grouping together duplicate elemnts
        sort(nums.begin(), nums.end());

        findSubset(nums, 0, ans, subset);
        return ans;
    }
};
