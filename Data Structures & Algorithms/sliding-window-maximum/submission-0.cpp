class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //     l
        //         r   
        //[1,2,1,0,4,2,6], k = 3
        //
        int l = 0, r=0;
        deque<int>dq;//
        vector<int>res;//
        while(r<nums.size())
        {
            
         //nums[1]>1
         //2>1
         //pop 1
         //dq = [2] , nums[2]>2, 1>2 false
         //dq = [2,1] nums[3]>1 0>1 false
         //dq = [2,1,0]
         //dq = [1, 0] nums[4]>0 4>0
         
            while(!dq.empty() && nums[r]>dq.back())
            {
                //dq = [1]
                dq.pop_back();
            }
            //[4, 1]
            dq.push_back(nums[r]);
           
            //1-0+1==k no
            //2-0+1 == 3
            //3-1+1 == 3
            //4-2+1==3 3==3 true
            if(r-l+1==k)
            {
                //max value
                //res = [2, 2]
                res.push_back(dq.front());
                //2 == nums[0] -> 2==1 false
                //2==nums[1] = 2==2 pop
                if(dq.front()==nums[l])
                {
                    //dq = [1, 0]
                    dq.pop_front();
                }
                //l=1
                //l=2
                l++;
            }
             //r=1
            //r=2
            //r=3
            //r=4
            
            r++;

        }
        //res = [2,2, 4, 4, 6]
        return res;
    }
};
