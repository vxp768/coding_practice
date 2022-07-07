/*
Given an array of integers arr, find the sum of min(b),
where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
*/

/* Sol: Idea is to figure out number of sub-arrays where the given number wll be minimum.
        Any number will be minimum atleast for single item array.
        For each idx find store first left idx smaller than current item and first right idx smaller 
        than current item.
        Then loop over each item in array and find num of sub arrays using left_arr and right_arr
        which has smaller number idx values.
        Take care of special case when the numbers can be same in array.
*/
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> l_arr(arr.size(), -1), r_arr(arr.size(), arr.size());
        int result=0;
        int mod = pow(10, 9) + 7;
        stack<int> S, R;
        S.push(0);
        for(int i=1; i<arr.size(); i++){
            
            if (arr[i] < arr[S.top()]){
                while(!S.empty() && arr[i] < arr[S.top()]){
                    S.pop();    
                }
                l_arr[i] = S.empty()?-1:S.top();
                S.push(i);
            } else {
                l_arr[i] = S.top();
                S.push(i);
            }
        }
        R.push(arr.size()-1);
        for(int i=arr.size()-2; i>=0; i--){
            if(arr[i] <= arr[R.top()]){
                while(!R.empty() && arr[i] <= arr[R.top()]){
                    R.pop();    
                }
                r_arr[i] = R.empty()?arr.size():R.top();
                R.push(i);
            } else {
                r_arr[i] = R.top();
                R.push(i);
            }
        }
        for(int i=0; i<arr.size(); i++){
            int left  = i - l_arr[i];
            int right = r_arr[i] - i;
            result = (result + left*right*(long)arr[i])%mod;
        }
        return result;
    }
};