class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n= heights.size();
        int l = 0, r=n-1;
        int maxArea = 0;
        //loop until two pointers meet 
        while(l<r)
        {
            //area between l and r, teh distance of index and min height out of two indices
//[1,7,2,5,4,7,3,6]
//        r=4
//        l=4
//area = 2*2=4
//maxArea = min(4,36) = 36;
            int area = (r-l)*min(heights[l], heights[r]);
            maxArea = max(area, maxArea);

            //move pointers based on height
            //shrink window if height at both indices is similar
            //7==7
            if(heights[r]==heights[l])
            {
                //r=4, l=2
                r--;
                l++;
            }
            //6>1
            //6>7 no
            //3>7 no
            //4>2
            else if(heights[r]>heights[l])
            {
                //l=4
                l++;
            }
            //r=6
            //r=5
            else
            {
                r--;
            }
        }
        //36=maxArea
        return maxArea;
    }
};
