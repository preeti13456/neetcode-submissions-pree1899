class Solution {
public:
    int jump(vector<int>& nums) {
        int maxJump = 0;
        int jumps = 0;
        int nextJump = 0;
        for(int i=0;i<nums.size(); i++)
        {
            if(i==nums.size()-1) continue;
            maxJump = max(maxJump, i+nums[i]);
            if(i==nextJump)
            {
                jumps++;
                nextJump = maxJump;
            }
        }
        return jumps;
    }
};
