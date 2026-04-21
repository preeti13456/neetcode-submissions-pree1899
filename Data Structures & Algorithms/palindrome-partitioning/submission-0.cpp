class Solution {
public:
vector<vector<bool>>computePalindrome(const string& s)
{
vector<vector<bool>>dp(s.size(), vector<bool>(s.size()));
for(int i=0; i<s.size(); i++)
{
    //diagonal values
    dp[i][i] = true;
    if(i<s.size()-1)
    {
        //non-diagnonal values
        dp[i][i+1]=s[i]==s[i+1];
    }
}
for(int length=3; length<=s.size(); length++)
{
    for(int i=0;i<s.size()-length+1; i++)
    {
        int start = i;
        int end = i+length-1;
        //Transitions
        dp[start][end] = dp[start+1][end-1]&&s[start]==s[end];
    }
}
return dp;

}
void backtrack(const string&s, int start, vector<string>&parts, vector<vector<string>>&result, const vector<vector<bool>>&is_palindrome)
{
    if(start==s.size()){
        result.push_back(parts);
        return;
    }
    for(int i=start; i<s.size(); i++)
    {
        if(is_palindrome[start][i])
        {
            parts.push_back(s.substr(start, i-start+1));
            backtrack(s, i+1, parts, result, is_palindrome);
            parts.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        //s="aab"
        vector<vector<bool>>is_palindrome = computePalindrome(s);
        vector<vector<string>>res;
        vector<string>parts;
        backtrack(s, 0, parts, res, is_palindrome);
        return res;
    }
};
