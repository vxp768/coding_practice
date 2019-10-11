class Solution {
public:
    string longestPalindrome(string s) {
        /* Brute Force*/
        string substr;
        int p_size = 0;
        if(s.size()==0){
            return s;
        }
        substr.append(1,s[0]);
        for(int i=0; i<s.size(); i++){
            string temp;
            temp.append(1,s[i]);
            for(int j=i+1; j<s.size(); j++){
                temp.append(1,s[j]);
                if(is_palindrome(temp)){
                    if (temp.size() > p_size){
                        p_size = temp.size();
                        substr = temp;
                    }
                }
            }
        }
        return substr;
    }
    bool is_palindrome(string s){
        int mid = s.size()/2;
        int end = s.size()-1;
        for(int i=0; i< mid; i++){
            if(s[i] != s[end]){
                return false;
            }
            end--;
        }
        return true;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if(size==0) return "";
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        int longest=1;
        int beg=0;
        for(int i=0; i<s.size(); i++){
            dp[i][i] = true;
        }
        for(int len=2; len<=s.size(); len++){
            for(int start=0; start<=s.size()-len; start++){
                int end = start+len-1;
                if (len == 2){
                    if(s[start] == s[end])
                         dp[start][end] = true;
                } else {
                   if(s[start] == s[end] && dp[start+1][end-1]==true)
                         dp[start][end] = true;
                }
                if (dp[start][end] == true) {
                    if(len>longest){
                        longest = len;
                        beg = start;
                    }
                }
            }
        }
        return s.substr(beg, longest);
    }
    
};
