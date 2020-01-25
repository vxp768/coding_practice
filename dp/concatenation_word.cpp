/*
Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.

 Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
 Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
*/

class Solution {
public:
    static bool string_sort(string a, string b){
        return a.size() < b.size();
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        //sort words wrt to size of words
        sort(words.begin(), words.end(), string_sort);
        unordered_set<string> str_set;
        vector<string> results;
        //check for each word if concat of word is possible
        for(int i=0; i<words.size(); i++){
            if(concat_words(words[i], str_set)==true){
                results.push_back(words[i]);
            }
            str_set.insert(words[i]);
        }
        return results;
    }
    //this tabulation method is from word break
    bool concat_words(string &word, unordered_set<string> &str_set){
        if(str_set.empty())
            return false;
        vector<bool> dp(word.size()+1, 0); 
        dp[0] = true;
        for(int len=1; len<=word.size(); len++){
            for(int j=0; j<len; j++){
                if(dp[j] && str_set.find(word.substr(j, len-j)) != str_set.end()){
                    dp[len] = true;
                    break;
                }
            }
        }
        return dp[word.size()];
    }
};


//      TRIE BASED
class Solution {
public:
    struct TrieNode {
        struct TrieNode *child[26];
        bool isWord;
        TrieNode() {
            isWord = false;
            for(int i=0; i<26; i++){
                child[i] = NULL;
            }
        }
    };
    struct TrieNode *trie_root;
    void addWord(struct TrieNode *root, string &word) {
        for(int i=0; i<word.size(); i++){
            if(root->child[word[i]-'a']==NULL){
                root->child[word[i]-'a'] = new TrieNode;
            }
            root = root->child[word[i]-'a'];
        }
        root->isWord = true;
    }
    bool concatedWord(struct TrieNode *root, string word, int lvl) {
        int i=0;
        for(i=0; i<word.size(); i++){
            if(root->isWord){
                if(concatedWord(trie_root, word.substr(i), lvl+1))
                    return true;
            }
            if (root->child[word[i]-'a'] == NULL) {
                return false;
            } else {
                root = root->child[word[i]-'a'];
            }
        }
        if(lvl==0){
            return false;
        } else {
            return root->isWord;
        }
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        trie_root = new TrieNode;
        vector<string> results;
        for(int i=0; i<words.size(); i++){
            if(words[i].size()>0)
                addWord(trie_root, words[i]);
        }
        for(int i=0; i<words.size(); i++){
            if(words[i].size()==0)
                continue;
            if(concatedWord(trie_root, words[i], 0)==true){
                results.push_back(words[i]);
            }
        }
        return results;
    }
};