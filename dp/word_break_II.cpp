/*
 Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
*/
//RECURSIVE
class Solution {
    unordered_set<string> str_set;
    vector<vector<string>> res_idx;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(int i=0; i<wordDict.size(); i++) {
            str_set.emplace(wordDict[i]);
        }
        vector<string> res;
        backtrack(s, 0, res);
        for(int i=0; i<res_idx.size(); i++){
            string tmp;
            for(int j=0; j<res_idx[i].size(); j++){
                tmp += res_idx[i][j] + " ";
            }
            tmp = tmp.substr(0,tmp.size()-1); //remove last space char
            res.push_back(tmp);
        }
        return res;
    }
    void backtrack(string &s, int start, vector<string>& res) {
        if(start == s.size()) {
            res_idx.push_back(res);
            return;            
        }        
        string sub;
        for(int i=start; i<s.size(); i++) {
            sub += s[i];
            if(str_set.find(sub) != str_set.end()) {
                res.push_back(sub);
                backtrack(s, i+1, res);
                res.pop_back();
            }
        }
        return;
    }
};
//MEMOIZATION:
class Solution {
    unordered_set<string> str_set;
    unordered_map<int, vector<string>> startidx_str;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(int i=0; i<wordDict.size(); i++) {
            str_set.emplace(wordDict[i]);
        }
        return backtrack(s, 0);
    }
vector<string> backtrack(string &s, int start) {
        vector<string> str_list;
        if(startidx_str.find(start) != startidx_str.end()){
            return startidx_str[start];
        }
        string sub;
        for(int i=start; i<s.size(); i++) {
            sub += s[i];
            if(str_set.find(sub) != str_set.end()) {
                if(i+1 == s.size()) {
                    str_list.push_back(sub);
                } else {
                    vector<string> tmp = backtrack(s, i+1);
                    for(int j=0; j<tmp.size(); j++){
                        str_list.push_back(sub+" "+tmp[j]);
                    }
                }
            }
        }
        startidx_str[start] = str_list;
        return str_list;  
    }
};