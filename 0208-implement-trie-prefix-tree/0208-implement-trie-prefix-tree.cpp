class TrieNode{

    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        isTerminal=false;
    }
};


class Trie {
    TrieNode* root;
public:
    Trie() {
        root= new TrieNode('\0');
    }

   void loopInsert(TrieNode* root, string word){

        for(int i=0;i<word.length();i++){

            int index=word[i]-'a';
            TrieNode* child;

            if(root->children[index]){
                root=root->children[index];
            }
            else{
                child= new TrieNode(word[i]);
                root->children[index]=child;
                root=child;
            }

        }

        root->isTerminal=true;
    }
    
    void insert(string word) {
        loopInsert(root, word);
    }

   

    bool loopSearch(TrieNode* root, string word, bool findPrefix){

        for(int i=0;i<word.length();i++){

            int index=word[i]-'a';

            if(root->children[index]){
                root=root->children[index];
            }
            else{
                return false;
            }
            
        }

        if(findPrefix){
            return true;
        }
        
        return root->isTerminal;
    }
    
    bool search(string word) {
        return loopSearch(root,word, false);
    }
    
    bool startsWith(string prefix) {
        return loopSearch(root,prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */