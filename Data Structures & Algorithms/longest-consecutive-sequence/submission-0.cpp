class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //Optimal approach using set data structure
        //how to check a number is starting of a sequence
        int n = nums.size();
        if(n==0) return 0;


        int longest = 1;
        
        unordered_set<int>st;
        for(int i=0; i<n; i++)
        {
            st.insert(nums[i]);
        }

        // To find longest sequence 
        for(auto it : st)
        {
            // if it is the strating element
            if(st.find(it-1)==st.end())
            {
                //we are able toi find the cosecutibe no.
                int cnt = 1;
                int x = it;
                while(st.find(x+1)!=st.end())
                {
                    x = x+1;
                    cnt = cnt+1;
                }
            longest = max(longest, cnt);
            }

        }
        return longest;
    }
};
