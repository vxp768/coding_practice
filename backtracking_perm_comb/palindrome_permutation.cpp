//Given a string, determine if a permutation of the string could form a palindrome.
/*
   Input: "code"
   Output: false
 */
class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> arr(128, 0);
        int count=0;
        for(int i=0; i<s.size(); i++){
            arr[s[i]]++;
            if(arr[s[i]] % 2 == 0)
                count--;
            else
                count++;
        }
        return count<=1;
    }
};
//LONGEST PALINDROME POSSIBLE IN A STRING
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> arr(128, 0);
        int even_len=0;
        int odd_len=0;
        for(int i=0; i<s.size(); i++){
            arr[s[i]]++;
        }
        for(int i=0; i<128; i++){
            if(arr[i]) {
                if(arr[i]%2==0)
                    even_len+=arr[i];
                else {
                    even_len += arr[i]-1;
                    odd_len += 1;
                }
            }
        }
        return odd_len==0?even_len:even_len+1;
    }
};
//ALL PALINDROMIC PERMUTATIONS Given a string s, return all the palindromic permutations (without duplicates) of it. 
//Return an empty list if no palindromic permutation could be form. aabb ===> ["abba", "baab"]
class Solution {
    string odd_char;
public:
    vector<string> generatePalindromes(string s) {
        int count=0;
        unordered_map<char, int> mp;
        vector<string> result;
        if(s.size()==0) return result;
        if(s.size()==1) {
            result.push_back(s);
            return result;
        }
        for(int i=0; i<s.size(); i++) {
            mp[s[i]]++;
            if(mp[s[i]]%2==0)
                count--;    //becomes even decrease
            else
                count++;    //becomes odd increment
        }
        if(count>1)
            return result;
        //Palindromes possible...generate first half of string
        //aaaabb ==== aab  ,  aabbcc ==== abc  ....find all perms
        odd_char = "";
        string half_char_set="";
        for(auto it=mp.begin(); it!=mp.end(); it++){
            if(it->second%2 ==1) {
                odd_char = it->first;
                it->second--;
            }
            if(it->second) {
                int count = it->second/2;
                while(count>0) {
                    half_char_set += it->first;
                    count--;
                }
            }
        }
        util(half_char_set, result, 0);    //generate all perms of half char set
        return result;    
    }
    void util(string &char_set, vector<string> &result, int idx) {
        if(idx==char_set.size()){
            //append reverse of string
            string rev = char_set;
            reverse(rev.begin(), rev.end());
            rev = char_set + odd_char + rev;
            result.push_back(rev);
            return;
        }
        unordered_set<char> st;
        for(int i=idx; i<char_set.size(); i++){
            if(st.count(char_set[i])==1) continue; //fix unique char at idx
            st.insert(char_set[i]);
            swap(char_set[i], char_set[idx]);
            util(char_set, result, idx+1);
            swap(char_set[i], char_set[idx]);
        }
    }
};