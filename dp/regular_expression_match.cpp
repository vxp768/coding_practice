/* Brtue force  */
/*
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.size()==0 && p.size()==0)
            return true;
        if(s.size()==0) {
            if(p.size()>=2){
                if(p[1]=='*'){
                    return isMatch(s, p.substr(2));
                }
            }
            return false;
        }
        return match(s, p, 0, 0);
    }
    bool match(string &s, string &p, int s_i, int p_i){
        
        if(s_i == s.size() && p_i==p.size()){
            return true;
        } else if(s_i == s.size()) {
            if(p_i+1 < p.size()){
                if(p[p_i+1]=='*'){
                    return match(s, p, s_i, p_i+2);
                }
            }
        } else if (s_i<0 || s_i > s.size() || p_i > p.size() || p_i<0){
            return false;
        }
        if(s[s_i] == p[p_i]){
            return match(s, p, s_i+1, p_i+1);
        } else if (p[p_i]== '.'){
            return match(s, p, s_i+1, p_i+1);
        } else if (p[p_i]=='*'){
            return match(s, p, s_i, p_i-1) ||      //repeat prev char
                   match(s, p, s_i, p_i+1) ||      //ignore *
                   match(s, p, s_i-1, p_i+1);      //zero of prev char in pattern
        } else {
            if(p_i<p.size()-1 && p[p_i+1]=='*')
                return match(s, p, s_i, p_i+2);
            else
                return false;
        }
    }
};


/* Better bruteforce....avoid multiple if else cases*/
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size()==0) return s.empty();
        bool first_match=false;
        if(s.size()>0 && (s[0] == p[0] || p[0] == '.')){
            first_match = true;
        }
        if(p.size()>=2 && p[1]=='*'){
                return isMatch(s, p.substr(2)) ||
                        (first_match && isMatch(s.substr(1), p));
        } else {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};


/* Method 3: DP */
