/*
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. 
Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. 
If it does not exist, output -1 for this number.

Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> S;
        vector<int> result;
        if(nums1.empty() || nums2.empty())
            return result;
        S.push(nums2[0]);
        for(int i=1; i<nums2.size(); i++){
            while(!S.empty() && nums2[i]>S.top()){
                int num = S.top();
                S.pop();
                mp[num] = nums2[i];
            }
            S.push(nums2[i]);
        }
        while(!S.empty()){
            int num = S.top();
            S.pop();
            mp[num] = -1;
        }
        for(int i=0; i<nums1.size(); i++){
            result.push_back(mp[nums1[i]]); 
        }
        return result;
    }
};

//JUST using map
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> result;
        for(int i=0; i<nums2.size(); i++){
            mp[nums2[i]] = i;
        }
        for(int i=0; i<nums1.size(); i++){
            int idx = mp[nums1[i]];
            int res = -1;
            for(int j=idx+1; j<nums2.size(); j++){
                if(nums2[j] > nums1[i]){
                    res = nums2[j];
                    break;
                }
            }
            result.push_back(res);
        }
        return result;
    }
};