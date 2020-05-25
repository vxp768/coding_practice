/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string 
containing only letters a-z or ..A "." means it can represent any one letter.

Example:
    addWord("bad")
    addWord("dad")
    addWord("mad")
    search("pad") -> false
    search("bad") -> true
*/
class WordDictionary {
    typedef struct Node_ {
        struct Node_ *child[26];
        bool is_word;
    } Node;
    Node *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node;
        for(int i=0; i<26; i++) {
            root->child[i] = NULL;
        }
        root->is_word = false;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        int idx=0;
        Node *node = root;
        if(word.size()==0) return;
        while(idx < word.size()){
            if(node->child[word[idx]-'a']==NULL){
                node->child[word[idx]-'a'] = new Node;
                node = node->child[word[idx]-'a'];
                for(int i=0; i<26; i++) {
                    node->child[i] = NULL;
                }
                node->is_word = false;
            } else {
                node = node->child[word[idx]-'a'];
            }
            idx++;
        }
        node->is_word = true;
    }
    
    bool search_sub(string word, Node *sub_root) {
        int idx=0;
        Node *node=sub_root;
        while(idx<word.size()){
            if(word[idx] == '.'){
                for(int j=0; j<26; j++){
                    if(node->child[j]){
                        if (search_sub(word.substr(idx+1), node->child[j])==true){
                            return true;
                        }
                    }
                }
                //if none of sub-tree found the word
                return false;
            } else if(node->child[word[idx]-'a']){
                node = node->child[word[idx]-'a'];    
            } else {
                return false;
            }
            idx++;
        }
        return node?node->is_word:false;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_sub(word, root);
    }
};