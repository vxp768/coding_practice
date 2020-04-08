//exactly one solution

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
        int diff;
        for (int i=0; i<nums.size(); i++){
            diff = target - nums[i];
          
            if (hash.find(diff) != hash.end()){
                result.push_back(hash[diff]);
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};


//TWO SUM LESS THAN K
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        int count=0;
        if(A.size()<2)
            return -1;
        sort(A.begin(), A.end());
        int max_sum=0;
        int sum;
        int left = 0, right = A.size()-1;
        while(left<right) {
            sum = A[left]+A[right];
            if(sum<K){
                max_sum = max(max_sum, sum);
                left++;
            } else {
                right--;
            }
        }
        return max_sum==0?-1:max_sum;
    }
};