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
        sort(num_sorted.begin(), num_sorted.end());
        reverse(num_sorted.begin(), num_sorted.end()); //starting from larger numbers make it faster to search
        return rec(0);     
    }
    bool rec(int n) {
        //try putting n in all of k buckets
        for(int i=0; i<bucket.size(); i++) {         
            if(bucket[i]+num_sorted[n] > target) continue; //try other bucket as sum is becoming more than target
            bucket[i] += num_sorted[n];
           
            if(n == num_sorted.size()-1) return true; //all nums have been put in bucket
            if (rec(n+1) == true) {
                return true;
            } else {
                bucket[i] -= num_sorted[n];
                if(bucket[i] == 0) 
                    return false; //don't try putting in other empty buckets
            }         
        }
        return false;
    }
};


// Another approach
class Solution {
    int target;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        vector<int> visited(nums.size(), 0);
        for(auto n: nums)
            sum+=n;
        if(sum%k != 0)
            return false;
        target = sum/k;
        sort(nums.begin(), nums.end(), greater<int>());
        return rec(nums, 0, visited, k, 0);     
    }
    bool rec(vector<int>& nums, int start_idx, vector<int>& visited, int k, int parti_sum) {
        if(k == 1) //at k=1 only final elems are left which will add to k
            return true;
         //if the numbers are only positive this condition is helps
         // if the numbers had -ve nos then this pruning cannot be used
        if(parti_sum>target) 
            return false;
        if(parti_sum == target) {
            //found 1 partition and k-1 more partitions needed
            return rec(nums, 0, visited, k-1, 0);
        }
        for(int i=start_idx; i<nums.size(); i++){
            if(visited[i]==0){
                visited[i] = 1;
                if (rec(nums, i+1, visited, k, parti_sum+nums[i]) == true)
                    return true;
                visited[i] = 0;
            }
        }
        return false;
    }
};