class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;

        function<void(int)>back = [&](int start)
        {
            res.push_back(temp);
            for(int i=start; i<nums.size(); i++)
            {
                temp.push_back(nums[i]);
                back(i+1);
                temp.pop_back();
;
            }
        };
        back(0);
return res;

    }
};
