/*
 Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s. 

 

Example 1:

Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
*/

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        //find the window with max freq of 1 and K 0s
        int max_freq=0;
        int max_window=0, left=0;
        int i=0;
        int ctr[2] = {0,0};
        for(i=0; i<A.size(); i++){
            ctr[A[i]]++;
            max_freq = max(max_freq, ctr[1]);
            if (i-left+1 > max_freq+K) {
                max_window = max(max_window, i-left);
                ctr[A[left]]--;
                left++;
            }
        }
        return max(max_window, i-left);
    }
};