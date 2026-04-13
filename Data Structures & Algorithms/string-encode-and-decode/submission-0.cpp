class Solution {
public:

//strs = ["neet", "code"]




    string encode(vector<string>& strs) {
        string ans;
        for(string&str : strs)
        //str = "neet" -> 24 or 32 bytes
        {
            const uint8_t len = static_cast<uint8_t>(size(str));
            ans.push_back(len);
            ans+=str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
for(int i=0; i<size(s);)
{
const size_t len = static_cast<uint8_t>(s[i++]);
ans.push_back(s.substr(i, len));
i+=len;
}
return ans;
    }
};
