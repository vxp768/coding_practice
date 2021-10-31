/*
Given a string s that consists of only uppercase English letters,
you can perform at most k operations on that string.

In one operation, you can choose any character of the string and
change it to any other uppercase English character.

Find the length of the longest sub-string containing all repeating 
letters you can get after performing the above operations.

Input:
s = "AABABBA", k = 1

Output:
4
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        //this is similar to finding k+1 distinct char of max size
        //and replace k of them with replace operation
        //only difference: the char with max frequency can occur any number of time
        
        //we need to find a window with a char having max frequency and k other char with any freq
        unordered_map<char, int> mp;
        int left=0;
        int max_freq=0, max_window=0;
        int i;
        for(i=0; i<s.size(); i++) {
            mp[s[i]]++;
            max_freq = max(max_freq, mp[s[i]]);
            
            if(i-left+1 > max_freq+k) { //max_freq+k represents max window so far
                //now window has one extra char...so acceptable window is "i-left" not "i-left+1"
                //AABA: correct window size = 4 for K=1
                //AABC: correct window size = 3
                //AAABCDEFGHCCCCCCCC, K=2
                max_window = max(max_window, i-left);
                mp[s[left]]--;
                left++;
            }
        }
        return max(max_window, i-left); //i-left needed if last char repeeats till end
    }
};


class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int res = 0;
        if(s.size()==0)
            return res;
        int left=0;
        int max_freq=0;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            max_freq = max(max_freq, mp[s[i]]);
            if(i-left+1 <= max_freq+k){
                res = max(res, i-left+1);
            } else {
              while(i-left+1 > max_freq+k ){
                    mp[s[left]]--;
                    left++;
              }  
            }
        }
        return res;
    }
};