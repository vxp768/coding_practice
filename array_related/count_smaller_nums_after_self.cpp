/*
You are given an integer array nums and you have to return a new counts array.
The counts array has the property where counts[i] is the number of smaller 
elements to the right of nums[i].
 
Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
*/
class Solution {
    vector<pair<int,int>> num_idx_pair; //nums,orig_idx
    vector<int> result;
public:
    vector<int> countSmaller(vector<int>& nums) {   
        vector<pair<int,int>> aux(nums.size(), {0,0});
         
        if(nums.size()==0) {
            return result;
        }
        if(nums.size()==1){
            result.push_back(0);
            return result;
        }
        result = vector<int>(nums.size(), 0);
        
        for(int i=0; i<nums.size(); i++){
            num_idx_pair.push_back({nums[i], i});
        }
        merge_sort(num_idx_pair, 0, num_idx_pair.size()-1, aux);
        
        return result;
    }
    void merge_sort(vector<pair<int,int>> &nums, int left, int right, vector<pair<int,int>> &aux) {
        if (left >= right)
            return;
        int mid = left + (right-left)/2;  
        merge_sort(nums, left, mid, aux);
        merge_sort(nums, mid+1, right, aux);
        merge(nums, left, mid, right, aux);
    }
    void merge(vector<pair<int,int>> &nums, int l, int mid, int r, vector<pair<int,int>> &aux) {
        for(int i=l; i<=r; i++){
            aux[i] = nums[i];
        }
        int num_right_to_left=0;
        int l_idx=l, r_idx=mid+1;
        
        for(int k=l; k<=r; k++){
            if (l_idx>mid){
                nums[k] = aux[r_idx++];
            } else if (r_idx > r){
                nums[k] = aux[l_idx]; 
                l_idx++;
                result[nums[k].second] += num_right_to_left;
            } else if (aux[l_idx].first <= aux[r_idx].first){
                nums[k] = aux[l_idx];
                l_idx++;
                result[nums[k].second] += num_right_to_left;
            } else { //r_num<l_num
                num_right_to_left++;
                nums[k] = aux[r_idx];
                r_idx++;
            }
        }
    }
};
