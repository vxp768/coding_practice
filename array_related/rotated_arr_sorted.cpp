/*
 * Given a sorted array which is rotated unknown number of times.
 * Find the minimum element.
 */
 // NO DUPLICATES
 class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int mid=0;
        
        while(l<r){
            if(nums[l] < nums[r]) //when sub-array elems are sorted
                return nums[l];
            
            mid = l+(r-l)/2;
            
            if(nums[mid] > nums[l]){
                l = mid+1;
            } else if (nums[mid] < nums[l]) {
                r = mid;
            } else {
                return min(nums[l],nums[r]); //when only two elems are left in sub-array
            }
        }
        return nums[l];
    }
};


///2nd method
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        
        while(l<r && nums[l]>nums[r]){
            int mid = l+(r-l)/2;
            if(nums[mid] >= nums[l]){
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
};
 
 

//////////////        DUPLICATES ALLOWED

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r = nums.size()-1;
        int mid=0;
        while(l < r){
            mid = l + (r-l)/2;
            if(nums[l] < nums[r])
                return nums[l];
            
            if(nums[mid] > nums[l]){
                l = mid+1;
            } else if (nums[mid] < nums[l]){
                r = mid;
            } else {
                l++;
            }
        }
        return nums[l];
    }
};

