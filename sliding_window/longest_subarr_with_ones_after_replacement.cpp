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
        int zero_count=0;
        int result=0;
        int start=0;
        for(int i=0; i<A.size(); i++){
            if(A[i]==0)
                zero_count++;
            while(zero_count>K){
                if(A[start]==0)
                    zero_count--;
                start++;
            }
            result = max(result, i-start+1);
        }
        return result;
    }
};