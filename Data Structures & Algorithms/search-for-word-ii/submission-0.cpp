class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //board dimesnions are row and columns 
        //0     1    2    3
     // 0 o     a    a    n
     // 1 e     t    a    e
     // 2 i     h    k    r
     // 3 i     f    l    v

     //words to search 
     //oath pea eat rain
     //  0   1   2    3

     int ROWS = board.size(); //4
     int COLS = board[0].size(); //4
     //4*4

     vector<string>res; //output we want in


     for(string& word : words)
     {
        bool flag = false;
        //0 to 4
        for(int r=0; r<ROWS && !flag; r++)
        {
            for(int c=0; c<COLS; c++)
            {
                //skip if at current cell we didn't find the start of our word

                if(board[r][c]!=word[0]) continue;
                //recursively check for the word by backtracking 
                if(backtrack(board, r, c, word, 0))//found case
                {
                res.push_back(word);
                flag = true;
                break;
                }
            }
        }
     }
    return res;
    }
private:
bool backtrack(vector<vector<char>>&board, int r, int c, string& word, int i)
{
    if(i==word.length()) return true; //reached end of word it's mayched
    if(r<0 || c<0 || r>=board.size() || c>=board[0].size()||board[r][c]!=word[i])
    return false;
    if(i == word.length() - 1) return true; // Final character match confirmed
    board[r][c] = '*';
    bool ret = backtrack(board, r+1, c, word, i+1) || backtrack(board, r-1, c, word, i+1) || backtrack(board, r, c+1, word, i+1)||backtrack(board, r, c-1, word, i+1);
    board[r][c] = word[i];
    return ret;
}
};