class Solution {
public:
void findCombination(vector<int>&candidates, int start, int t, vector<vector<int>>&ans, vector<int>&combinations){
    if(t==0)
    {
        ans.push_back(combinations);
        return;
    }
    for(int i=start; i<candidates.size(); i++)
    {
        //skip duplicates
        if(i>start && candidates[i]==candidates[i-1]) continue;

//if any number has value greater then target eill ksip it 
        if(candidates[i]>t) break;

        //recursion and backtrack
        combinations.push_back(candidates[i]);
        findCombination(candidates, i+1, t-candidates[i], ans, combinations);
        combinations.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>combinations;
        sort(candidates.begin(), candidates.end());
        findCombination(candidates, 0, target, ans, combinations);
        return ans;
    }
};
