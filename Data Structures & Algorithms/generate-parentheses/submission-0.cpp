class Solution {
public:
vector<string>res;
    vector<string> generateParenthesis(int n) {
        string line(n*2, ' ');
        generateParenthesis(n , 0, 0, line);
        return res;
    }
    void generateParenthesis(int n, int open, int close, string &line)
    {
        if(open==n && close==n)
        {
            res.push_back(line);
            return;
        }
        //no. of open brackets greater thenn close
        if(open > close)
        {
            line[open+close] = ')';
            generateParenthesis(n, open, close+1, line);
        }

        if(n!=open)
        {
            line[open+close] = '(';
             generateParenthesis(n, open+1, close, line);
            
        }
    }
};
