class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> final_result = {{}};
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int new_num = nums[i];
            int count =0;
            //count duplicates
            while(count+i<nums.size() && nums[i]==nums[count+i]) {
                count++;    
            }
            i = i+count-1;
            int subset_size = final_result.size();
            for(int j=0; j<subset_size; j++) {
                vector<int> tmp_subset = final_result[j];
                int k=count;
                while(k){
                    tmp_subset.push_back(new_num);
                    final_result.push_back(tmp_subset);
                    k--;
                }
            }
        }
        return final_result;
    }
};

//RECURSIVE brute force
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        vector<int> vec;
        subsetsWithDup(res, nums, vec, 0);
        return res;
    }
private:
    void subsetsWithDup(vector<vector<int>> &res, vector<int> &nums, vector<int> &vec, int begin) {
        res.push_back(vec);
        for (int i = begin; i != nums.size(); ++i) {
            if (i == begin || nums[i] != nums[i - 1]) {
                vec.push_back(nums[i]);
                subsetsWithDup(res, nums, vec, i + 1);
                vec.pop_back();
            }
        }
    }
};