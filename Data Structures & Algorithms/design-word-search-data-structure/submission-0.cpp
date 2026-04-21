class WordDictionary {
public:
struct TrieNode
{
bool isWord;
unordered_map<char, TrieNode*>children;
TrieNode(): isWord(false){};
TrieNode(bool val): isWord(val){};
};
TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        //day
        TrieNode* temp = root;
//d///1 iyteration for d it' added into the temp -> d
//a 
        for(char c : word)
        {
            //d->a /not the case
            if(!temp->children.contains(c))
            //a
            //d->a
            temp->children[c] = new TrieNode();
            //d
            //d
            temp = temp->children[c];
        }
        temp->isWord = true;

    }
    
    bool search(string word) {
        return search(word, 0, root);
    }
    bool search(string word, int pos, TrieNode* node)
    {
        //we alredy serached all if it's wprd we return true else return false
        //if you have checked all characters 
        if(pos==word.size())
        {
            //return true if node marks end of word
            if(node->isWord) return true;
            return false;
        }
        char c = word[pos];
        if(c!='.')
        {
            if(!node->children.contains(c)) return false;
            return search(word, pos+1, node->children[c]);

        }
        for(auto child:(node->children))
        if(search(word, pos+1, child.second ))return true;

        return false;
    }
};
