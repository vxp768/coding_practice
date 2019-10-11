//sorted array can have both -ve and +ve nums
//square them in such a way that result is also sorted

//STORE RESULT IN NEW ARRAY

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int left=0, right=A.size()-1;
        vector<int> result(right+1, 0);
        int index=right;
        while(left <= right && A[left]<0) {
            int l_sq = A[left]*A[left];
            int r_sq = A[right]*A[right];
                if (r_sq > l_sq) {
                    result[index--] = r_sq;
                    right--;
                }else {
                    result[index--] = l_sq;
                    left++;
                }
        }
        while(right>=left){
            result[index--] = A[right]*A[right];
            right--;
        }
        return result;
    }
};