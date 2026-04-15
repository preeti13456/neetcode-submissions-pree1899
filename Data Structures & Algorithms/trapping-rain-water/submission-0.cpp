class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i=0;
        int ans = 0;
        int j = n-1;
        int max_left = 0;
        int max_right = 0;
 //      i       j       
//[0,2,0,3,1,0,1,3,2,1]
        while(i<j)
        {
            //
            max_left = max(max_left, height[i]);//0
            max_right = max(max_right, height[j]);//1
            if(height[i]<=height[j])
            {
                if(max_left>height[i])
                {
                    ans+=(max_left-height[i]);
                }
                i++;
            }
            else
            {
                if(height[j]<max_right)
                {
                    ans+=(max_right-height[j]);
                }
                j--;
            }
        }
        return ans;
    }
};
