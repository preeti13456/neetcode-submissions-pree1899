class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        


        //map of 26 characters
        vector<int>rightmost(26);
//"xyxxyzbzbbisl"
        for(int i=0; i<s.length(); i++)
        //x=3
        //y=4
        //z=7
        //b=9
        //i=10
        //s=11
        //l=12
        rightmost[s[i]-'a'] = i;
        int left = 0;
        int right = 0;
        for(int i=0; i<s.length(); i++)
        {
            //for x 1st iteration
            //right = max(0, 3)=3
            //right = max(3,4) = 4
            //right = max(4, 7) = 7
            //right = max(7, 9) = 9
            //right = 10
            //right = 11
            //right = 12
            right = max(right, rightmost[s[i]-'a']);
            //12==12
            if(right==i)
            {
                //ans = 11
                ans.push_back(right-left+1);
                //left = 13
                left=i+1;
            }
        }
return ans;
    }
};
