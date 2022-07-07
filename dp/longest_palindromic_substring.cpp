/*

*/
//BRUTE FORCE
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
//DP bottom-up
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

//EXPAND AROUND CENTER
/*
In fact, we could solve it in O(n^2)O(n 
2
 ) time using only constant space.

We observe that a palindrome mirrors around its center. Therefore, a palindrome can be 
expanded from its center, and there are only 2n - 1 such centers.

You might be asking why there are 2n - 1 but not nn centers? The reason is the center of a 
palindrome can be in between two letters.
Such palindromes have even number of letters (such as "abba") and its center are between the two 'b's.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen=0, beg=0;
        
        for(int i=0; i<s.size(); i++){
            int len1 = expand(s, i, i); //odd case
            int len2 = expand(s, i, i+1); //even case
            int len = max(len1, len2);
            if (len > maxLen){
                maxLen = len;
                beg = i - (len-1)/2 ; //start idx will be left of i
            }
        }
        return s.substr(beg, maxLen);
    }
    int expand(string &s, int left, int right){
        
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
};