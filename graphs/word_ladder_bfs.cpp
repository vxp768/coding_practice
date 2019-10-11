/*
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> Q;
        Q.push(beginWord);
        int ladder_len=1; //includes being and end word
        
        while(!Q.empty()) {
            //process all adjacencies of previous word
            int size = Q.size();
            for(int adj=0; adj<size; adj++){ 
                string to_process = Q.front();
                Q.pop();
                if(to_process == endWord) {
                    return ladder_len;
                }
              
                //for each char in word try replacing them with all char 1 by 1
                //add all adjacencies to Q
                for(int i=0; i<to_process.size(); i++) {
                    char c_orig = to_process[i];
                    for(int ch=0; ch<26; ch++) {
                        char c = 'a' + ch;
                        to_process[i] = c;
                        if(dict.find(to_process) != dict.end()) {
                            Q.push(to_process);
                            //remove word from set to make sure it is not processed again
                            dict.erase(to_process);
                        }
                    }
                    to_process[i] = c_orig;
                }
                
            }
            ladder_len++;
        }
        return 0;
    }
};

//CAN RUN BFS IN BOTH DIRECTION
