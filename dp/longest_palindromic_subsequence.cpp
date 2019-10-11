
//BRUTE FORCE
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int count;
        if(s.size()==0) return 0;
        
        count = LPS(s, 0, s.size()-1);
        return count;
    }
    int LPS(string &s, int start, int end) {
        int count=0;
         if(start > end)
            return 0;
        if(start == end)
            return 1;
            
        if(s[start]==s[end]) {
            count = 2+LPS(s, start+1, end-1);
        } else {
            count = max(LPS(s, start+1, end), LPS(s, start, end-1));
        }
        return count;
    }
};
//MEMOIZATION
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size()==0) return 0;
        
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return LPS(s, 0, s.size()-1, dp);
    }
    int LPS(string &s, int start, int end, vector<vector<int>> &dp) {
        int count=0;
        if(start > end)
            return 0;
        if(start == end)
            return 1;
        if(dp[start][end] != -1)
            return dp[start][end];
        
        if(s[start]==s[end]) {
            dp[start][end] = 2+LPS(s, start+1, end-1, dp);
        } else {
            dp[start][end] = max(LPS(s, start+1, end, dp), LPS(s, start, end-1, dp));
        }
        return dp[start][end];
    }
};

//TABULATION
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size()==0) return 0;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        //strings of len=1
        for(int i=0; i<s.size(); i++){
            dp[i][i] = 1;
        }
        //Table: start to end
        for (int len=2; len<=s.size(); len++){
            for(int start=0; start<=s.size()-len; start++){
                int end = start+len-1;
                if (len==2 && s[start]==s[end]){
                    dp[start][end] = 2;
                } else if (s[start]==s[end]) {
                    dp[start][end] = 2+dp[start+1][end-1];
                } else {
                    dp[start][end] = max(dp[start+1][end], dp[start][end-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};