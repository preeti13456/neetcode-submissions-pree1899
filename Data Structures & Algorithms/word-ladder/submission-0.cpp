class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
     //beginWord = "cat"
     //endWord = "sag"
     //wordList=["bat", "bag", "sag", "dag", "dot"]
     //cat -> bat -> bag -> sag 

//{bat, bag, sag, dag, dot}
     unordered_set<string>st{wordList.begin(), wordList.end()};
     queue<pair<string, int>>q;
     //{cat, 1}
     q.push({beginWord, 1});

     while(!q.empty())
     {
        string word = q.front().first;
        int level = q.front().second;
        q.pop();

        //boundary case
        if(word==endWord) return level;

//c a t
        for(int i=0; i<word.size(); i++)
        {   
            //og=c
                char og = word[i];
                for(char c='a'; c<='z'; c++)
                {
                    word[i] = c;
                    //if set contains the word 

                    //word = cat
                    if(st.count(word))
                    {
                        q.push({word, level+1});
                        st.erase(word);
                    }
                }
                word[i] = og;
        }
     }
     return 0;
    }
};
