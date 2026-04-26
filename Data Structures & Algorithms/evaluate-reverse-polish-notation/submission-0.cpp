class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //traverse each token
        //if number push into stack
        //if operator pop two elments apply operation and push result back
        //top of stack return 
        map<string, function<int(int, int)>>ops;
        ops["+"] = [](int a, int b) {return a+b;};
        ops["-"] = [](int a, int b) {return a-b;};
        ops["*"] = [](int a, int b) {return a*b;};
        ops["/"] = [](int a, int b) {return a/b;};

        stack<int>st;

        for(auto s: tokens)
        {
            //if the value present in tokens not operator 
            if(s!="+" && s!="-" && s!="*" && s!="/")
            {
                st.push(stoi(s));
            }
            else
            {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                st.push(ops[s](b,a));
            }
        }
        return st.top();
    }
};
