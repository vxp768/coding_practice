/*
Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
*/

//RECURSIVE O(2^n-1)
//worst case "aaaaab" and all possible prefix of string is in dictionary
class Solution {
    unordered_set<string> str_set;
    vector<int> dp;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        str_set.clear();
        for (int i=0; i<wordDict.size(); i++) {
            str_set.emplace(wordDict[i]);
        }
        return rec(s, 0);
    }
    bool rec(string &s, int start) {
        if(start==s.size()) return true;
        string sub;
        for(int e=start; e<s.size(); e++){
            sub += s[e];
            if((str_set.find(sub) != str_set.end()) && rec(s, e+1)) {
                return true;
            }
        }
        return false;
    }
};
//MEMOIZATION O(n^2)
/* Important to store both sucessful and failure result in dp[]....else in worst case it will call all recursive options and time out*/
class Solution {
    unordered_set<string> str_set;
    vector<int> dp;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        str_set.clear();
        dp = vector<int>(s.size(), -1);
        
        for (int i=0; i<wordDict.size(); i++) {
            str_set.emplace(wordDict[i]);
        }
        return rec(s, 0);
    }
    bool rec(string &s, int start) {
        if(start==s.size()) return true;
        string sub;

        if(dp[start] != -1) {
            return dp[start];
        }
        for(int e=start; e<s.size(); e++){
            sub += s[e];
            if((str_set.find(sub) != str_set.end()) && rec(s, e+1)) {
                dp[start]=1;
                return true;
            }
        }
        dp[start] = 0;
        return false;
    }
};
//TABULATION O(n^2)
class Solution {
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> str_set;
        for(int i=0; i<wordDict.size(); i++) {
            str_set.emplace(wordDict[i]);
        }
        vector<int> dp(s.size()+1, 0);
        dp[0] = true;
        string sub;
        for(int len=1; len<=s.size(); len++) {
            //TRY for each len
            for(int j=0; j<len; j++){
                //start from 0 and loop for "len" 
                //dp[j] for certain len then substr for remaining string
                if(dp[j] && (str_set.find(s.substr(j, len-j))!=str_set.end())) {
                    dp[len] = 1;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};