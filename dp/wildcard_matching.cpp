/*
Given an input string (s) and a pattern (p),
implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

*/

//Brute force...time limit exceed
class Solution {
public:
    bool isMatch(string s, string p) {
        
        if(p.size() == 0)
            return s.empty();
        
        if (s.size() ==0){
            if(p[0] == '*')
                return isMatch(s, p.substr(1));
            else
                return false;
        }
        if(s[0] == p[0] || p[0] == '?'){
            return isMatch(s.substr(1), p.substr(1));
        } else if (p[0] == '*'){
            return isMatch(s.substr(1), p.substr(1)) || // * is 1 char
                    isMatch(s, p.substr(1)) || //* is ignored...considered empty seq
                     isMatch(s.substr(1), p); // * = multiple char
        } else {
            return false;
        }
    }
};

//DP memoization
class Solution {
    vector<vector<int>> dp;
public:
    bool isMatch(string s, string p) {
        
        dp = vector<vector<int>> (s.size()+1, vector<int>(p.size()+1, -1));
        dp[0][0] = rec(s, p, 0, 0);
        
        return dp[0][0]==1?true:false;
    }
    int rec(string& s, string &p, int s_i, int p_i) {
        
        if(p_i == p.size()) {
            if (s_i == s.size())
                return 1; //reached end of pattern and string
            else
                return 0; //reached end of pattern but not string
        }
        if(dp[s_i][p_i] != -1){ //already processed substring starting at s_i and p_i
            return dp[s_i][p_i];
        }
        if(s_i == s.size()) {
            if(p[p_i] == '*'){
                dp[s_i][p_i] = rec(s, p, s_i, p_i+1);
                return dp[s_i][p_i];
            } else {
                return 0;
            }
        }
        if(s[s_i] == p[p_i] || p[p_i] == '?'){
            dp[s_i][p_i] = rec(s, p, s_i+1, p_i+1);
            return dp[s_i][p_i];
        }
        if(p[p_i] == '*'){
            if(rec(s,p, s_i+1, p_i+1) == 1 || //* as 1 char
                rec(s,p, s_i, p_i+1) == 1 ||  //ignore *
                 rec(s,p, s_i+1, p_i) == 1) { //* as multiple char
                dp[s_i][p_i] = 1;
            } else {
                dp[s_i][p_i] = 0;
            }
            return dp[s_i][p_i];
        } else {
            dp[s_i][p_i] = 0;
            return dp[s_i][p_i]; //chars don't match
        }
    }
};