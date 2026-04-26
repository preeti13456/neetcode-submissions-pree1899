class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<string , int>cache;

        function<int(int, int)>recursive=[&](int i, int curr)
        {
            if(i==n)
            {
                return curr==target?1 : 0;

            }
            string key = to_string(i)+","+to_string(curr);
            if(cache.count(key)) return cache[key];
            int pos = recursive(i+1, curr+nums[i]);
            int neg = recursive(i+1, curr-nums[i]);
            cache[key] = pos+neg;
            return cache[key];
        };
        return recursive(0,0);
    }
};
