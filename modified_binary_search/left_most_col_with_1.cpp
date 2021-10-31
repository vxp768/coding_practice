/*
 left most column in a matrix with atleast one '1'

 [0, 0]
 [1, 1]       ans =0
  
 [0, 0, 1]
 [0, 1, 1]    ans =1
*/

//Basic binary search
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimen = binaryMatrix.dimensions();
        int row = dimen[0];
        int col = dimen[1];
        int min_col_idx = INT_MAX;
        for(int r=0; r<row; r++) {
            if(binaryMatrix.get(r,col-1) ==0)
                continue;
            int left=0, right=col-1, mid=0;
            int prev_mid, num_mid;
            
            // binary search on row to find first 1
            while(left <= right) {
                mid = left + (right-left)/2;
                prev_mid = 0;
                num_mid  = binaryMatrix.get(r, mid);
                if(left == right) {
                   // when single elem is left
                    if(num_mid == 1) {
                            min_col_idx = min(left, min_col_idx);
                    }
                    break;
                } else if(left + 1 == right){
                    // when two elems are left
                    if(num_mid == 1) {
                            min_col_idx = min(left, min_col_idx);
                    } else {
                        prev_mid  = binaryMatrix.get(r, right);
                        if(prev_mid == 1)
                            min_col_idx = min(right, min_col_idx);
                    }
                    break;
                } else {
                    // 3 elems or more
                    if(num_mid ==1) {
                        prev_mid = binaryMatrix.get(r, mid-1);
                        if(prev_mid == 0){
                            min_col_idx = min(mid, min_col_idx);
                            break;
                        }
                        right = mid-1;
                    } else {
                        left = mid+1;
                    }
                }
            }
        }
        return min_col_idx==INT_MAX?-1:min_col_idx;
    }
};



//Binary serach...less Code
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimen = binaryMatrix.dimensions();
        int row = dimen[0];
        int col = dimen[1];
        int min_col_idx = INT_MAX;
        int num_mid;
        int left=0, right=col-1, mid=0;
        for(int r=0; r<row; r++) {
            if(binaryMatrix.get(r,col-1) ==0)
                continue;
            left=0; right=col-1; mid=0;
            
            while(left <= right) {
                mid = left + (right-left)/2;
                num_mid  = binaryMatrix.get(r, mid);
                if(left == right) {
                    if(num_mid == 1) {
                            min_col_idx = min(left, min_col_idx);
                    }
                    break;
                } else {
                    if(num_mid ==1) {
                        min_col_idx = min(mid, min_col_idx);
                        right = mid;
                    } else {
                        left = mid+1;
                    }
                }
            }
        }
        return min_col_idx==INT_MAX?-1:min_col_idx;
    }
};

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimen = binaryMatrix.dimensions();
        int row = dimen[0];
        int col = dimen[1];
        int min_col_idx = col;
        
        int r=0, c=col-1;
        while(r<row && c>=0){
          if(binaryMatrix.get(r,c)==1){
              min_col_idx = min(c, min_col_idx);
              c--;
          } else {
              r++;
          }
        }
        
        return min_col_idx==col?-1:min_col_idx;
    }
};