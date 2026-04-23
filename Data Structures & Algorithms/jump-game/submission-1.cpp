class Solution {
public:
    bool canJump(vector<int>& nums) {
        //[1, 2, 0, 1, 0]
        int jump = 1;
        for(int i=0; i<nums.size(); i++)
        {
            jump--;
            jump = max(jump, nums[i]);
            if(jump==0 && i!=nums.size()-1) return false;
        }
        return true;
    }
};
