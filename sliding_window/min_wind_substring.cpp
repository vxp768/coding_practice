/*
Given a string S and a string T, find the minimum window in S 
which will contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
*/
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        int start = 0, end = 0, counter;
        int min_l=0, min_r=s.size()-1, min_len = INT_MAX;
        
        for(auto c: t) {
            map[c]++;
        }
        counter = t.size();
        
        while(end < s.size()) {            
            if (map[s[end]] > 0){
                counter--;
            }
            map[s[end]]--;
            end++;
            
            while (counter == 0){
                //window has all chars
                if (end - start < min_len) {
                    min_l = start;
                    min_r = end;
                    min_len = end - start; //end points to 1 char after window
                }
                //start shrinking window
                map[s[start]]++;
                if(map[s[start]] > 0){
                    counter++;
                }
                start++;                
            }            
        }
        if (min_len != INT_MAX) {
            return s.substr(min_l, min_len);
        }
        return "";
    }
};