/*
 * Longest repeating (duplicate) substring in a given string
 * 1. Use DP to solve it
 * 2. Use binary search and rabin-karp algo
 * 3. Use KMP
 */
 
 //DP (On^2)
iclass Solution {
public:
    int longestRepeatingSubstring(string S) {
        vector<vector<int>> dp(S.size()+1, vector<int>(S.size()+1));
        int max_val=0, val=0;
        for (int i=0; i<S.size(); i++) {
            for(int j=0; j<i; j++) {
                if(S[j] == S[i]) {
                    dp[i+1][j+1] = dp[i][j]+1;
                    val = dp[i+1][j+1];
                    max_val = max(val, max_val);
                }
            }
        }
        return max_val;
    }
};
 
/*
 *  Binary Search and rabin-karp O(nlogn)
 */
class Solution {
    int MAX_CHAR;
    unsigned long modulo; //to avoid overflow of hash since max_char and pat_len could be large
    set<unsigned long> hash_set;
    vector<unsigned long> POW;
public:
    int longestRepeatingSubstring(string S) {
        MAX_CHAR = 26;
        modulo = pow(2, 24);
        int p = 1;
        for (int i = 0; i < S.size(); i++) {   //This is to take care of overflow of hash values
            POW.push_back(p);
            p = (p*MAX_CHAR)%modulo;
        }
        /*
          If repeated substring of length k exists then 
          repeated substring of all lengths less than k also exists.
          So using binary search find the length of longest repeating. substr.
        */
        
        int left=1, right=S.size();
        while(left<=right) {
            int len = left + (right-left)/2;
            if(search(S, len) == -1) {
                //not found...reduce the length
                right = len -1;
            } else {
                //found...increase the length
                left = len+1;
            }
        }
        //left-1 since after last match...it is increased by 1
        return left-1;
    }
    int search(string S, int len) {
        unsigned long hash = 0;
        //unsigned long d = pow(MAX_CHAR, len-1);
        unsigned long d = POW[len-1];
        for (int i=0; i<=S.size()-len; i++) {
            if(i==0) {
                for (int j=0; j<len; j++) {
                    hash = (hash*MAX_CHAR + S[j])%modulo;
                } 
                hash_set.insert(hash);
            } else {
                hash = ((hash - d*S[i-1])*MAX_CHAR + S[i+len-1])%modulo;
                if(hash_set.find(hash)!=hash_set.end()) {
                    return i;
                } else {
                    hash_set.insert(hash);
                }
            }
        }
        return -1;
    }
};