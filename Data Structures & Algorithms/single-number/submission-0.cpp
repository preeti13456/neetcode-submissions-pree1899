class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // XOR -> different bits 1 , same bits 0 
        //so two values which are same they cance out each other

        //xor result in , any number xor with 0 is teh no.
        int ans = 0;
        //we can just look at one osition  output bit will comes from same value 
       // xor to res, set the res back , we know res that the ans has teh single number that we try to return 
        for(int num : nums)
        {
            ans^=num;
        }
        return ans;
    }
};
