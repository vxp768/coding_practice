/*
Given an integer array sorted in ascending order, write a function to search target in nums. 
If target exists, then return its index, otherwise return -1. However, the array size is unknown to you. 
You may only access the array using an ArrayReader interface, where ArrayReader.get(k) returns the element of the array at index k (0-indexed).

You may assume all integers in the array are less than 10000, and if you access the array out of bounds, ArrayReader.get will return 2147483647.

Input: array = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4 
*/
class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int low = 0, high=0;
        if(reader.get(low) == target)
            return low;
        high=1;
        while(reader.get(high) < target) {
            low  = high;
            high = high*2;
        }
        while(low<=high){
            int mid = low+(high-low)/2;
            int read = reader.get(mid);
            if(read == target)
                return mid;
            if(target < read) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return -1;
    }
};