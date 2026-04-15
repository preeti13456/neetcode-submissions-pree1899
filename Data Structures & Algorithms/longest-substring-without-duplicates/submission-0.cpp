class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //s=zxyzxyz
        //length = 3;
        int ptr = 0;
        unordered_map<int, int>m;
        int ans = 0;
        for(int i=0; i<s.size(); i++)
        {
            m[s[i]]++;//z=1, x=1, y=1, 
            while(m[s[i]]>1)
            {
                m[s[ptr]]--;
                ptr++;
            }
            ans = max(ans, i-ptr+1);
        }
        return ans;

    }
};
