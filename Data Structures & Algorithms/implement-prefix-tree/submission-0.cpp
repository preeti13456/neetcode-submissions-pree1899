class TrieNode
{
public:
TrieNode* children[26]; //arrayof child pointers one for each letter 

bool endWord; //marks completion
TrieNode()
{
for(int i=0; i<26; i++)
{
    children[i] = nullptr;
}
    endWord = false;
}
};
class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
         root = new TrieNode();  
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word)
        {
            int i=c-'a';
            if(curr->children[i]==nullptr)
            {
                curr->children[i] = new TrieNode();

            }
            curr=curr->children[i];

        }
        curr->endWord = true; //words ends here after insertion
    }
    
  bool search(string word) {
        TrieNode* curr = root;
        for(char c : word)
        {
            int i=c-'a';
            if(curr->children[i]==nullptr)
            {
                return false;
            }
            curr = curr->children[i];
        }
        return curr->endWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c: prefix)
        {
        int i=c-'a';
            if(curr->children[i]==nullptr)
            {
                return false;
            }
            curr = curr->children[i];
        }
        return true;
    }
};
