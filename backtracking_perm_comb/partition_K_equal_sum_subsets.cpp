/*
 Given an array of integers nums and a positive integer k,
 find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

  Brute force: assume "K" buckets instead of 2 as in partition array in two equal subset sum.
            Put n items into k bucket so each bucket has same total item value.
                For each bucket, try all possible content O(k*2^n)            -- no good.
                For each item, try all possible destined bucket O(n^k)        -- doable.
*/

class Solution {
    vector<int> bucket;
    vector<int> num_sorted;
    int target;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto n: nums) sum+=n;
        if(sum%k != 0) return false;
        target = sum/k;
       
        int size = nums.size();
        bucket = vector<int> (k,0);
        num_sorted = vector<int> (nums);
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        return rec(0);     
    }
    bool rec(int n) {
        //try putting n in all of k buckets
        for(int i=0; i<bucket.size(); i++) {         
            if(bucket[i]+num_sorted[n] > target) continue; //try other bucket as sum is becoming more than target
            bucket[i] += num_sorted[n];
           
            if(n == num_sorted.size()-1) return true; //all nums have been put in bucket
            if (rec(n+1)) return true;
            else {
                bucket[i] -= num_sorted[n];
                if(bucket[i] == 0) return false; //don't try putting in other empty buckets
            }         
        }
        return false;
    }
};