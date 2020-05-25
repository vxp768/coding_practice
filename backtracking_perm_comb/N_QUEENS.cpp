//PLACE N QUEENS on chess board of size nXn
// Give all possible arrangements

class Solution {
    vector<vector<string>> final_result;
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> chess(n, vector<int>(n,0));
        vector<string> result(n, string(n, '.'));
       
        backtrack(n, 0, chess, result);
        return final_result;
    }
    void backtrack(int n, int row, vector<vector<int>> chess, vector<string> result) {
        if(n==0) {
            final_result.push_back(result);
            return;
        }
        for(int c=0; c<chess[0].size(); c++){
            if(check_validity(row, c, chess)==true){
                chess[row][c]=1;
                result[row][c] = 'Q';
                backtrack(n-1, row+1, chess, result);
                chess[row][c]=0;
                result[row][c] = '.';
            } 
        }
        return;
    }
    bool check_validity(int row, int col, vector<vector<int>>& chess){
       //check column
       for(int r=row; r>=0; r--){
           if(chess[r][col]==1)
               return false;
       } 
       //check diagonal...backwards
        int r=row, c=col;

        while(r>=0 && c>=0){
            if(chess[r][c]==1)
                return false;
            r--;
            c--;
        }
        //check diagonal...forwards
        r=row;c=col;
        while(r>=0 && c<chess[0].size()){
            if(chess[r][c]==1)
                return false;
            r--;
            c++;
        }
        return true;
    }
};