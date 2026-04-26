class Solution {
public:

    bool checkValidString(string s) {
       return check(s, '(', ')') && check(string(s.rbegin(), s.rend()), ')', '(');
    }
    bool check(const string&s, char ob, char cb)
{
 int closing = 0, opening = 0, wildcard = 0;
 for(char c : s)
 {
    if(c==cb) closing++;
    else if(c==ob) opening++;
    else wildcard++;
    if(closing > opening + wildcard) return false;
 }   
 return true;
}

};
