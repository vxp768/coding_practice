/*
Find the kth smallest element in an unsorted array.
Example 1:
    Input: [3,2,1,5,6,4] and k = 2
    Output: 2
*/
///       QUICK SELECT
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        random_shuffle(nums.begin(), nums.end());
        return kth_smallets(nums, 0, nums.size()-1, k);  //k is the correct idx of elem
    }
    
    int kth_smallets(vector<int> &nums, int l, int r, int k) {
        
        int pos = partition(nums, l, r);
        if(pos == k){
            return nums[pos];
        }
        if(pos < k){
            return kth_smallets(nums, pos+1, r, k); //search in right sub array
        }
        return kth_smallets(nums, l, pos-1, k); //search left sub array
    }
    
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low;
        for(int j=low; j<=high -1; j++) {
            if(nums[j] <= pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[high]);
        return i;
    }
};