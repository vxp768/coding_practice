/* Find all the possible path from "begin" to "end" word
 * wordList has list of allowed words. only one letter can change at one time
 * 
 * run bfs on the path
 */
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //unordered_map<string, int> visited;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> result;
       
        int ladder=1;
        int shortest_path=INT_MAX;
        
        queue<vector<string>> Q;
        vector<string> tmp;
        tmp.push_back(beginWord);
        Q.push(tmp);
        if(dict.find(beginWord) != dict.end()){
            dict.erase(beginWord);
        }
        vector<string> visited_words;
        while(!Q.empty()) {
            int size = Q.size(); //size of child at same layer
            for(auto it= visited_words.begin(); it!=visited_words.end(); it++){
                dict.erase(*it);
            }
            visited_words.clear();
            for(int paths=0; paths<size; paths++){
                vector<string> path_to_process = Q.front();
                Q.pop();
                if(path_to_process.size()>=shortest_path){
                    break;
                }
                //pick the last word in path
                string last_str = path_to_process.back();              
                for(int i=0; i<last_str.size(); i++){
                    char c_orig = last_str[i];
                    
                    //try replacing each char and search new word in dict
                    for(int j=0; j<26; j++) { 
                        last_str[i] = 'a'+j;
                        if(dict.find(last_str) != dict.end()){
                            path_to_process.push_back(last_str);
                            Q.push(path_to_process);
                            if(last_str != endWord) {
                                visited_words.push_back(last_str);
                                //deleting here can cause some of the paths to be missed in final solution
                                //dict.erase(last_str);
                            } else {
                                //found shortest path
                                shortest_path = ladder+1;
                                result.push_back(path_to_process);
                            }
                            path_to_process.pop_back();    
                        }
                    }
                    
                    last_str[i] = c_orig;
                }
            }
            ladder++;
        }
        return result;
    }
};