/*
 *  Given a string S, check if the letters can be rearranged 
 *  so that two characters that are adjacent to each other are not the same. 
 */
class Solution {
public:
    string reorganizeString(string S) {
       
        vector<pair<char, int>> count(26);
        priority_queue<pair<int, char>> pq;
        string result="";
        
        for(int i=0; i<S.size(); i++) {
            count[S[i]-'a'].first = S[i];
            count[S[i]-'a'].second++;
        }
        for(int j=0; j<26; j++){
            if(count[j].second){
                pq.push(make_pair(count[j].second, count[j].first));
            }
        }
        if(pq.top().first > (S.size()+1)/2)
            return "";
        
        pair<int, char> prev(0,' ');
        while(!pq.empty()){
            pair<int, char> cur = pq.top();
            pq.pop();
            result += cur.second;
            cur.first--;
            if(prev.first>0)
                pq.push(prev);
            prev = cur;
        }
        return result;
    }
};