/* 
 * Given a string, find all possible permutations
 * 
 */

// without dups: str = abcd
void util(string &str, vector<string> &result, int idx) {
    if(idx==str.size()){
        result.push_back(str);
        return;
    }
    for(int i=idx; i<str.size(); i++){
        swap(str[i], str[idx]);
        util(str, result, idx+1);
        swap(str[i], str[idx]);
    }
}

//with dups: str = aabcdee
void util(string &str, vector<string> &result, int idx) {
    if(idx==str.size()){
        result.push_back(str);
        return;
    }
    unordered_set<char> st;
    for(int i=idx; i<str.size(); i++){
        if(st.count(str[i])==1) continue; //fix unique char at idx
        st.insert(str[i]);
        swap(str[i], str[idx]);
        util(str, result, idx+1);
        swap(str[i], str[idx]);
    }
}