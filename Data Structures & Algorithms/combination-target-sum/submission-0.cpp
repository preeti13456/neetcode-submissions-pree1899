class Solution {
public:
void findCombinations(vector<int>&nums, int i, int target, vector<vector<int>>&ans,
vector<int>&combinations)
{
    //base case
    if(target<0 || i==nums.size()) return;
    if(target==0)
    {
        ans.push_back(combinations);
        return;
    }
    ///[3,4,5]
    //target = 16
    //c = [3]
    //findcomb([3,4,5], 0, 13, [[3]], [3])
    //findComb([3,4,5], 0, 10, [[3,3]], [3,3])
    //findComb([3,4,5], 0, 7, [[3,3,3]], [3,3,3])
    //findComb([3,4,5], 0, 4, [[3,3,3,3]], [3,3,3,3])
    //findComb([3,4,5], 0, 0, [[3,3,3,3,4]], [3,3,3,3,4])

    if(nums[i]<=target)
    {
        combinations.push_back(nums[i]);
        findCombinations(nums, i, target-nums[i], ans, combinations);
        combinations.pop_back();
            }
            findCombinations(nums, i+1, target, ans, combinations);

}
//
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        //explore different wsys
        //reuse multiple tiems
        //order doesn't matter
//         nums = [3,4,5]
// target = 16

// Output: [[3,3,3,3,4],[3,3,5,5],[4,4,4,4],[3,4,4,5]]
//either pick or not pick and continue picking till teh sum of the numbers in our picking arry becomes equal to target 

//Approach:
//1.include current number 
//dupliactes allowd be on same index reduce target by 1 
//backtrack after return 
//exclude current number , move to next index

//target 0 : valid comb  ad res
//target<0 pop the path 

vector<vector<int>>ans;
vector<int>combinations;
findCombinations(nums, 0, target, ans, combinations);
return ans;
    }
};
