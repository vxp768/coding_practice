/*
  Write a function to generate the generalized abbreviations of a word. 
  Input: "word"
  Output:
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 */
 class Solution {
    vector<string> result;
public:
    vector<string> generateAbbreviations(string word) {
        rec(word, 0, "", false);
        return result;
    }
    void rec(string word, int start, string abr, bool prev_num){
        if(start == word.size()){
            result.push_back(abr);
            return;
        }
        rec(word, start+1, abr+word[start], false); //add char as char
        if(prev_num == false) {
            int num=0;
            for(int i=start; i< word.size(); i++){  //abbrv char to num
                num++;
                rec(word, i+1, abr+to_string(num), true);
            }
        }
    }
};