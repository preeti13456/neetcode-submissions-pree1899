class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //create a map and two pointer approach
        //s1 = "abc", s2 = "lecaabee"
        //output false
        unordered_map<char, int>let1, let2;
        for(int i=0; i<s1.size(); i++)
        {
            //a:1, b:1, c:1
            //let1 = [(a,1), (b,1), (c,1)]
            ++let1[s1[i]];
        }
        //                   l
        //                            r
        //l   e   c   a   a   b   e   e
        int l = 0;
        int r = 0;
        while(r<s2.size())
        {
            //let1[l] false
            //let1[a]
            if(let1[s2[r]]>0)
            {
                //c=0 //a=0
                --let1[s2[r]];
                r++;

                if(r-l==s1.size())
                return true;
            }
            else if(l<r)
            {
                //c=1 //a=1
                ++let1[s2[l]];
                ++l;
            }
            else
            {
                ++l;
                ++r;
            }
        }
        return false;
    }
};
