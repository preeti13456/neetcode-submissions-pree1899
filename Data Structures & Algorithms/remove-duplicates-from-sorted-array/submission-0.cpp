class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int currElement = nums.at(0);
        for(int i=1; i<size; i++)
        {
            if(nums.at(i)==currElement)
            {
                for(int j=i; j<size-1; j++)
                {
                    nums.at(j)=nums.at(j+1);
                }
                --size;
                --i;
            }
            else
            {
                currElement = nums.at(i);
            }
        }
        return size;
    }
};