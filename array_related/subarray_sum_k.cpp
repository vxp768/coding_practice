/*
  The idea behind this approach is as follows: If the cumulative sum(repreesnted by sum[i]sum[i] for sum upto i^{th}i th
  index) upto two indices is the same, the sum of the elements lying in between those indices is zero. 
  Extending the same thought further, if the cumulative sum upto two indices, say ii and jj is 
  at a difference of kk i.e. if sum[i] - sum[j] = ksum[i]−sum[j]=k, the sum of elements lying between indices ii and jj is kk.
 
 * [2, 3, 5, 4, 1] ,   k=5
 * 0,1
 * 2,1 
 * 5,1          sum-k == 0  = 1
 * 10,1         sum-k == 0  = 1
 * 14,1         sum-k == 9  = 0
 * 15,1         sum-k == 5  = 1
 * 
 */
//two pointer sliding window will not work as numbers can be negative

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        int result=0;
        if (size == 0) return 0;
        int sum=0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i=0; i<size; i++){
            sum += nums[i];
            result += mp[sum -k];
            mp[sum] += 1;
        }
        return result;
    }
};