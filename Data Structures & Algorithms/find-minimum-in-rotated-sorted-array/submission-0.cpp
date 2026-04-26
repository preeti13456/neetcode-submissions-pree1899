class Solution {
public:
    int findMin(vector<int> &nums) {
        //         l     r
        //3, 4, 5, 6, 1, 2
        int n = nums.size();
        //edge cases and boundary condition
        //we hve only one value in 
        if(n==1) return nums[0];
        //first value hi choti hai 
        //first valeu is lesser the. last array not sorted
        //return first 
        if(nums[0]<=nums[n-1]) return nums[0];

//calcuale distamce from middle elembr to left and right to middle 
        auto myabs = [](int a, int b)
        {
            return a>b ? (a-b) : (b-a);
        };
        int l = 0; //0
        int r = n-1; //r=5
        int m;
        //5-0 >1
        while(r-l>1)
        {
            //m = 0+5/2 = 2
            //m = 2+(5-2)/2 = 3
            //m=3+(5-3)/=4
            m=l+(r-l)/2;
            //nums[2] = 5
            //whichever side has bigger difference 
            //dl = | 5 - 3| = 2
            //dr = |2-5| = 3
            //dl = |6-5| = 1
            //dr = |6-2| = 4
            //dl = |2-1| = 1
            //dr = |6-1| = 5
            int dl = myabs(nums[m], nums[l]);
            int dr = myabs(nums[r], nums[m]);
            if(dl>dr) r=m;
            //dl<dr
            //l=2
            //l=3
            else l=m;
        }
        return nums[r];
    }
};
