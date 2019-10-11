/*
 longest substring with atmost k distinct chars in string
*/
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp;
        int left=0;
        int len=INT_MIN;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            if(mp.size()<=k) {
                len = max(len, i-left+1);
                continue;
            }
            while(mp.size()>k){
                mp[s[left]]--;
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                }
                left++;
            }
        }
        return len==INT_MIN?0:len;
    }
};

//Using array...assume max type of char is 256
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> ctr(256, 0);
        int distinct=0, left=0;
        int len=0;
        
        for(int i=0; i<s.size(); i++){
            if(ctr[s[i]]==0){
                distinct++;
            }
            ctr[s[i]]++;
            if(distinct<=k){
                len = max(len, i-left+1);
                continue;
            }
            while(distinct>k){
                ctr[s[left]]--;
                if(ctr[s[left]]==0)
                    distinct--;
                left++;
            }
        }
        return len;
    }
};