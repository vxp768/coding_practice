/*   Given a collection of distinct integers, return all possible permutations.
         No duplicates   [1, 2, 3]
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        util(nums, result, 0);
        return result;
    }
    void util(vector<int>& nums, vector<vector<int>>& res, int idx)
    {
        if(idx == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = idx; i<nums.size(); i++){
            swap(nums[i], nums[idx]);
            util(nums, res, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
};
/*   Given a collection of distinct integers, return all possible permutations.
     Duplicates  allowed  [1, 2, 3, 2]
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        util(nums, result, 0);
        return result;
    }
    void util(vector<int>& nums, vector<vector<int>>& res, int idx)
    {
        if(idx == nums.size()){
            res.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for(int i=idx; i<nums.size(); i++){
            if (st.count(nums[i]) == 1) { continue; }   //count is on avg constant time...worst case it could be linear
            st.insert(nums[i]);
            swap(nums[i], nums[idx]);
            util(nums, res, idx+1);
            swap(nums[i], nums[idx]);
        }
    }
};

//Without using set....sort the numbers
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());       //important to sort the numbers otherwise we will have repeatition of perms
        perm(nums,0,result);
        return result;
    }
    void perm(vector<int>nums, int idx, vector<vector<int>>& result) {
        if(idx==nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++) {
            //fixing number at idx...don't want same number to come at idx again    
            if(i==idx || nums[i]!=nums[idx]) { //skip same numbers
                swap(nums[i], nums[idx]);
                perm(nums, idx+1, result);
            }
        }
    }
    /* Using set is best solution...check other submissions */
};