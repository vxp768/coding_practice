class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> aux(nums.size(), 0);
        merge_sort(nums, aux, 0, nums.size()-1);
        return nums;
    }
    void merge_sort(vector<int>& nums, vector<int>& aux, int lo, int hi){
        if(lo>=hi)
            return;
        int mid = lo + (hi-lo)/2;
        merge_sort(nums, aux, lo, mid);
        merge_sort(nums, aux, mid+1, hi);
        merge(nums, aux, lo, mid, hi);
    }
    void merge(vector<int>& nums, vector<int>& aux, int lo, int mid, int hi) {
        for(int i=lo; i<=hi; i++){
            aux[i] = nums[i];
        }
        int i=lo, j=mid+1;
        for(int k=lo; k<=hi; k++){
            if(i>mid){
                nums[k] = aux[j++];
            } else if (j>hi){
                nums[k] = aux[i++];
            } else if(aux[i]<aux[j]){
                nums[k] = aux[i++];
            } else {
                nums[k] = aux[j++];
            }
        }
    }
};