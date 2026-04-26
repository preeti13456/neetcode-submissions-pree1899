class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        


        //map of 26 characters
        vector<int>rightmost(26);

        for(int i=0; i<s.length(); i++)
        //x=0, y=1
        //x=2 x=3
        //y=2
        rightmost[s[i]-'a'] = i;
        int left = 0;
        int right = 0;
        for(int i=0; i<s.length(); i++)
        {
            right = max(right, rightmost[s[i]-'a']);
            if(right==i)
            {
                ans.push_back(right-left+1);
                left=i+1;
            }
        }
return ans;
    }
};
