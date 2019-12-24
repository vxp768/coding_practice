/*
  In Place sorting...no auxilary space
  Not Stable: elements with equal keys can be re-ordered
  Avg Case: O(NlogN)
  Worst Case: O(N^2) when array already sorted
   
  When input array size gets smaller than say 10...we can use insertion sort instead of calling QuickSort recursively.
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick(nums, 0, nums.size()-1);
        return nums;
    }
    void quick(vector<int>& nums, int low, int high) {
        if (low < high) {
            int p = partition(nums, low, high);
            quick(nums, low, p-1);
            quick(nums, p+1, high);
        }
    }
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int pIdx = low;
        for(int j=low; j<high; j++){
            if(nums[j] <= pivot){
                swap(nums[pIdx], nums[j]);
                pIdx++;
            }
        }
        swap(nums[pIdx], nums[high]);
        return pIdx;
    }
    
    //In case you want randomized....this can also cause increase in runtime..depending on the array pattern
        int randomized_partition(vector<int> &nums, int low, int high){
        /* initialize random seed: */
        srand (time(NULL));
        int random = (rand() % (high-low))+low;
        swap(nums[high], nums[random]);
        return partition(nums, low, high);
    }
    
    //Iterative partition
        int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[low];
        int l = low, r = high;
        while(true) {
            while(nums[l] <= pivot){
                l++;
                if (l == high) break;
            }
            while(nums[r] >= pivot){
                r--;
                if (r == low) break;
            }
            if (l>=r) break;
            swap(nums[l], nums[r]);
        }
        swap(nums[low], nums[r]);
        return r;
    }
};

