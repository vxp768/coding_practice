/*
 * Sort colors
 * we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, high=nums.size()-1, mid=0;
        
        while(mid <= high) {
            if(nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
                //don't increment mid as new value needs to be processed again
            } else if (nums[mid]==0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else { //nums[mid]==1
                mid++;   
            }
        }
    }
};