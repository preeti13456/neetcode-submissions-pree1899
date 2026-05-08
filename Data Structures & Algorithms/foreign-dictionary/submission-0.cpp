class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        //order maintain kra hai current nodes are given in form of string of words
// Input: ["hrn","hrf","er","enn","rfnn"]

// Output: "hernf"
//given words are already sorted 
//longer word always omes after shrter word if prefix matches

//first word come after this word that is meant by lexicographically smaller word 
//go by character by caharceter each word and fidn different character 
//words are sorted on based on most significant bit 

//n comes before f
//n<f
//h  r  n
//h  r  f
string res = "";
//if there exist a cycle in our graph and contradictory the sequene of character order will return empty string 
//track marking teh nod eis already been visited or processed 
unordered_map<char, vector<char>>adjList; //based on ordering of chaarcters

unordered_map<char, int> indegree;

for(string word: words)
{
    for(char c : word)
    //as we are starting from there
    indegree[c] = 0;
}

for(int i=0; i<words.size()-1; i++)
{
    string word1 = words[i];
    string word2 = words[i+1];

    //min length of both of teh oword s
    //edge case
    //prefix check but the first word length is big then the next word
    if(word1.length()>word2.length() && word1.substr(0, word2.length())==word2)
    return "";

    int l1 = 0, l2 =0;
    //move ahead for smae chaacrerters in both wor
    while(l1 < word1.length() && l2<word2.length() && word1[l1]==word2[l2])
    {
        l1++;
        l2++;
    }
    //if we have different word and word1 comes before word2
    if(l1<word1.length() && l2<word2.length())
    {
        adjList[word1[l1]].push_back(word2[l2]);
        indegree[word2[l2]]++;
    }
}
//DFS
queue<char>q;
for(auto it : indegree)
{
    if(it.second == 0)
    q.push(it.first);
}
while(!q.empty())
{
    char front = q.front();
    q.pop();
    res+=front;
    for(char next : adjList[front])
    {
        indegree[next]--;
        if(indegree[next]==0)
        q.push(next);
    }
}
return res.length()==indegree.size()?res : "";


    }
};
