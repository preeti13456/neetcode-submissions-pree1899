class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // if string is empty we cn't validate 

        string res;
        stack<int>st;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(!st.empty())
                {
                    st.pop();
                }
                else
                {
                    s[i] = '\0';
                }
            }
        }
    //edge case for empty value
        while(!st.empty())
        {
            s[st.top()] = '\0';
            st.pop();
        }

        for(char c : s)
        {
            if(c!='\0')
            {
                res+=c;
            }
        }
        return res;
    }
};
