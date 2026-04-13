class Solution {
public:
    int numDecodings(string s) {
        int pre_ways=1, i_ways=1, prev;
        //if size doesn't exist 
        if(!s.size())return 0;

        //first indexed elemnt 0 we return 0 as tehre is dno decodng avalibl e
        if(s[0]=='0') return 0;
        int n = s.size();
        for(int i=1; i<n; i++)
        {
            prev=i_ways;
            if(s[i]=='0') i_ways = 0;
            //range is between 10 to 26
            if((s[i-1]=='1') || (s[i-1]=='2' && s[i]<'7'))i_ways+=pre_ways;
            pre_ways = prev;
        }
        return i_ways;
    } 
};
