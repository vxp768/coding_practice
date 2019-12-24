/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.
Input: candidates = [2,3,6,7], target = 7,      A solution set is:        [ [7], [2,2,3] ]
*/
class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size()==0)
            return result;
        sort(candidates.begin(), candidates.end()); 
        vector<int> tmp;
        util(candidates, target, tmp, 0);
        return result;
    }
    void util(vector<int> &nums, int sum, vector<int> tmp, int idx) {
        if(sum==0) {
            result.push_back(tmp);
            return;
        }
        if(sum<0)
            return;
        for(int i=idx; i<nums.size(); i++){
            if(nums[i] > sum)
                return;
            tmp.push_back(nums[i]);
            util(nums, sum-nums[i], tmp, i);
            tmp.pop_back();
        }
    }
};