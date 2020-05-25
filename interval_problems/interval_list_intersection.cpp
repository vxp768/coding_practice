/*
 * Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
 * Return the intersection of these two interval lists.
 * 
 */

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        if (A.size()==0 && B.size()==0){
            return result;
        }
        for (int i=0, j=0; i<A.size()&&j<B.size(); ) {
            if (A[i][1] < B[j][0]) i++;
            else if (B[j][1] < A[i][0]) j++;
            else {
                result.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
                if (A[i][1] < B[j][1]) i++;
                else j++;
            }
        }
        return result;
    }
};