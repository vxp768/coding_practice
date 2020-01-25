/* Maximum Length of a Concatenated String with Unique Characters
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
*/
//Using bit sets
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp;
        int result=0;
        int j;
        for (int i=0; i<arr.size(); i++) {
            
            bitset<26> str_bits;
            //set bits corresponding to all chars
            for (j=0; j<arr[i].size(); j++){
                if(str_bits[arr[i][j]-'a'] == 1){
                    break;  //if chars repeat...ignore the string
                }
                str_bits[arr[i][j]-'a'] = 1;
            }
            //all unique chars
            if(j == arr[i].size()) {
                //loop through all the bitset pushed in dp vector
                //these bitset in vector corresponds to all combination of string concat with unique characters
                for(int k=0; k<dp.size(); k++) {
                    bitset<26> tmp = dp[k];
                    if( (tmp & str_bits)==0 ) {
                        //no common char
                        dp.push_back(str_bits|tmp);
                    }
                }
                dp.push_back(str_bits);
            }
        }
        //return maxlength of entry in dp
        for(int i=0; i<dp.size(); i++){
           result = max(result, (int)dp[i].count()); 
        }
        return result;
    }
};

// USING BACKTRACKING
class Solution {
public:
    int maxLength(vector<string>& arr) {
        if(arr.size()==0)
            return 0;
        return backtrack(arr, "", 0);
    }
    int backtrack(vector<string>& arr, string str, int idx){
        unordered_set<char> str_set(str.begin(), str.end());
        int len=0;
        if(str_set.size()!=str.size()){
            return 0;
        }
        len = str.size();
        for(int i=idx; i<arr.size(); i++){
            len = max(len, backtrack(arr, str+arr[i], i+1));
        }
        return len;
    }
};