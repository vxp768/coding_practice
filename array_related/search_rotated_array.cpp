/*
 *  Search in rotated array wihtout dups
 *
 */
 
 class Solution {
public:
    int search(vector<int>& nums, int target) {
         //One solution is to find rotation_idx and then Binary search
         //2nd method with single binary search loop
         int l = 0, r = nums.size()-1;
         int mid;
         while(l<=r){
              mid = l + (r - l)/2;
              if (nums[mid] == target){
                  return mid;
              }
              //One of the partition has to be sorted
              if(nums[l] <= nums[mid]){
                //left side is sorted
                if (target >= nums[l] && target < nums[mid]){
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
              } else {
                //right side is sorted
                if (target > nums[mid] && target <= nums[r]){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
             }
         }
    return -1;
    }
};


////    ROTATED ARRAY WITH DUPS
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0; int high = nums.size()-1;
        int mid;
        while(low<=high){
            while(low < high && nums[low] == nums[low+1]){
                low++;
            }
            while(low<high && nums[high]==nums[high-1]){
                high--;
            }
            
            mid = low + (high-low)/2;
            
            if(nums[mid]==target)
                return true;
            
            if(nums[low] <= nums[mid]){
                //left is sorted
                if(target >= nums[low] && target < nums[mid]) {
                    high = mid -1;
                } else {
                    low = mid+1;
                }    
            } else {
                //right is sorted
                if(target <= nums[high] && target > nums[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};