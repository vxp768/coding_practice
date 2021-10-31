//Generate all the subsets from array of unique integers

//BRUTE FORCE RECURSIVE
class Solution {
    vector<vector<int>> final_result;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> res;
        rec(nums, res, 0);
        return final_result;
    }
    void rec(vector<int>& nums, vector<int> result, int idx) {
        if(idx==nums.size()) {
            final_result.push_back(result);
            return;
        }
        //not taken
        rec(nums, result, idx+1);
        result.push_back(nums[idx]);
        //taken
        rec(nums, result, idx+1);
    }
};

//ITERATIVE WAY
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> final_result;
        for(int i=0; i<nums.size(); i++) {
            int new_num = nums[i];
            vector<vector<int>> tmp_subsets;
            for(int j=0; j<final_result.size(); j++) {
                vector<int> tmp = final_result[j];
                tmp.push_back(new_num);             //add new num to all existing vectors
                tmp_subsets.push_back(tmp);
            }
            for(auto it=tmp_subsets.begin(); it!=tmp_subsets.end(); it++){
                final_result.push_back(*it);
            }
            final_result.push_back(vector<int>{new_num});
        }
        final_result.push_back(vector<int>{});
        return final_result;
    }
};

//REALLY REALLY SMART ITERATION
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> final_result= {{}}; //init makes the size 1
        for(int i=0; i<nums.size(); i++) {
            int new_num = nums[i];
            int subset_size_sofar = final_result.size();
            for(int j=0; j<subset_size_sofar; j++) {
                final_result.push_back(final_result[j]);  //push set in end
                final_result.back().push_back(new_num);   // add new num to the set added above
            }
        }
        return final_result;
    }
};