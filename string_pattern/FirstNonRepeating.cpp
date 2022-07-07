#include<bits/stdc++.h>
using namespace std;

/*
Given a stream of char find first non-repeating char till that char
*/
vector<char> FindFirstNonRepeatingCharacter(string S){
    unordered_map<char, int> mp;
    queue<char> Q;
    vector<char> result;
    cout<<S<<endl;
    for(int i=0; i<S.size(); i++){
        mp[S[i]]++;
        if (mp[S[i]]==1){
            Q.push(S[i]);    
        }
        while(!Q.empty()){
            if(mp[Q.front()] > 1){
                Q.pop();
            }  else {
                break;
            }
        }
        if(Q.size() == 0){
            result.push_back('0');
        } else {
            result.push_back(Q.front());
        }
    }
    return result;
}