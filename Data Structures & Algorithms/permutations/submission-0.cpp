class Solution {
public:
void findPermutes(vector<int>&nums, int start, vector<vector<int>>&ans)
{
    if(start==nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for(int i=start; i<nums.size(); i++)
    {
        swap(nums[i], nums[start]);
        findPermutes(nums, start+1, ans);
        swap(nums[i], nums[start]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        //fixed one position and check for remaining elemnts recursively 
        //fix current index start , iterate throuh remaining elments 
        vector<vector<int>>ans;
//         Input: nums = [1,2,3]

// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
        findPermutes(nums, 0, ans);
        return ans;
    }
};
