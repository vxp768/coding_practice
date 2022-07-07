/*
Given an integer array nums and two integers lower and upper, 
return the number of range sums that lie in [lower, upper] inclusive.

Range sum S(i, j) is defined as the sum of the elements in 
nums between indices i and j inclusive, where i <= j.

Example 1:
Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.

Example 2:
Input: nums = [0], lower = 0, upper = 0
Output: 1 */

class Solution {
    int result;
    int lower1, upper1;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        lower1 = lower;
        upper1 = upper;
        vector<long> sum(nums.size()+1, 0);
        vector<long> aux(nums.size()+1, 0);
        result=0;
        sum[0] = 0; //sum=0 takes care of comparing with idx=0 
        for(int i=1; i<=nums.size(); i++){
            sum[i] = sum[i-1] + nums[i-1];
        }
        //sort sum array and find number of range satisfying the condition
        merge_sort(sum, 0, sum.size()-1, aux);
        return result;
    }
    void merge_sort(vector<long> &sum, int left, int right, vector<long> &aux) {
        if(left>=right)
            return;
        int mid = left + (right-left)/2;
        merge_sort(sum, left, mid, aux);
        merge_sort(sum, mid+1, right, aux);
        merge(sum, left, mid, right, aux);
    }
    void merge(vector<long> &sum, int left, int mid, int right, vector<long> &aux) {
        for(int i=left; i<=right; i++){
            aux[i] = sum[i];
        }
        int i = left;
        int l_i = left, r_i=mid+1;
        int r_low = mid+1, r_high = mid+1;
        while (l_i <= mid) {
            //if left satisfies below 2 conditions all elems after left will also satisfy as subarr is sorted
            while(r_low  <= right  && aux[r_low]  - aux[l_i] < lower1)  r_low++;
            while(r_high <= right  && aux[r_high] - aux[l_i] <= upper1) r_high++;
            
            while(r_i <= right && aux[r_i] < aux[l_i]){
                sum[i++] = aux[r_i++];
            }
            result += r_high - r_low;
            sum[i++] = aux[l_i++];
        }
        while (r_i <= right){
            sum[i++] = aux[r_i++];
        }
    }
};


/////      TLE

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int result=0;
        vector<long> sum(nums.size(), 0);
        sum[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            sum[i] = sum[i-1] + nums[i];
        }
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                
                if (i==0){
                    if(sum[j] >= lower && sum[j] <= upper){
                        result++;
                    }    
                } else {
                    int diff = sum[j] - sum[i-1];
                    if (diff >= lower && diff <= upper){
                        result++;
                    }
                }
            }
        }
        return result;
    }
};
