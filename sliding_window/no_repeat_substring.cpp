/*Given a string,
 
  find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int max_len=0;
        int left=0;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            if(mp.size() == i-left+1) {
                max_len = max(max_len, i-left+1);
                continue;
            }
            //mp size gives number of unnique char in window
            while(mp.size()<i-left+1){
                //there are repeating chars in mp
                mp[s[left]]--;
                if(mp[s[left]]==0) {
                    mp.erase(s[left]);
                }
                left++;
            }
        }
        return max_len;
    }
};