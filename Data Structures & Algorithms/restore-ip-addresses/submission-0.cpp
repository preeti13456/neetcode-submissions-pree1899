class Solution {
public:
vector<string>result;
//current i address string
void backtrack(string s, int index, int parts, string current)
{
    //edge case 4 dots and reach end of string
    //good case
    if(parts ==4 && index==s.size())
    {
        //append current ip address
        //4th dot shuld be at end resmove that 
        result.push_back(current.substr(0, current.size()-1));
        return;
    }
    //invalid ip address
    if(parts==4 || index==s.size())
    return;


    for(int len=1; len<=3&&index+len<=s.size(); len++)
    {
        string segment = s.substr(index, len);
        //avoid trailing zero
        if(segment.size()>1 && segment[0]=='0')
        continue;

        if(stoi(segment)>255)
        continue;

        backtrack(s, index+len, parts+1, current+segment+".");
    }
}
    vector<string> restoreIpAddresses(string s) {
        //we can't extend any ip address range beyond 255
        //even after plaing the dots no digit should left out hence i have just one concern 
        //that if we have length > 12 wouldn't it e a prob

        backtrack(s, 0, 0, "");
        return result;
    }
};