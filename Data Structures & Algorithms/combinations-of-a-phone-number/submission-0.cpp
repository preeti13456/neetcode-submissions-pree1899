class Solution {
    unordered_map<char, vector<char>>map;
    vector<string>res;
public:
Solution()
{
    map['2'] = {'a', 'b', 'c'};
        map['3'] = {'d', 'e', 'f'};
        map['4'] = {'g', 'h', 'i'};
        map['5'] = {'j', 'k', 'l'};
        map['6'] = {'m', 'n', 'o'};
        map['7'] = {'p', 'q', 'r', 's'};
        map['8'] = {'t', 'u', 'v'};
        map['9'] = {'w', 'x', 'y','z'};
}
    vector<string> letterCombinations(string digits) {
        string curr;
        backtrack(digits, curr, 0);
        return res;
    }
    void backtrack(const string&digits, string&curr, int i)
    {
        if(curr.size()==digits.size())
        {
            if(!curr.empty()) res.push_back(curr);
            return;

        }
        //for 3 in 34 digits what is the corresponding letter in map
        char digit = digits[i];
        //lookup letters over the digit map 
        for(char letter : map[digit])
        {
            //d
            curr.push_back(letter);
            backtrack(digits, curr, i+1);
            curr.pop_back();
        }
    }

};
