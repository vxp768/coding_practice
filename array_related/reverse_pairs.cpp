/*
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

Example 1:
Input: nums = [1,3,2,3,1]
Output: 2

Example 2:
Input: nums = [2,4,3,5,1]
Output: 3
*/

class Solution {
    int result;
public:
    int reversePairs(vector<int>& nums) {
        result = 0;
        vector<int> aux(nums.size(), 0);
        merge_sort(nums, 0, nums.size()-1, aux);
        return result;
    }
    void merge_sort(vector<int>& nums, int left, int right, vector<int>& aux) {
        if (left>=right)
            return;
        
        int mid = left + (right-left)/2;
        merge_sort(nums, left, mid, aux);
        merge_sort(nums, mid+1, right, aux);
        merge(nums, left, mid, right, aux);
    }
    void merge(vector<int>& nums, int left, int mid, int right, vector<int>& aux) {
        int l_i = left, r_i = mid+1;
        int p = mid+1;
        for(int i=left; i<=right; i++){
            aux[i] = nums[i];
        }
        /*
          When right array is being copied don't increment result
        */
        int i = l_i;
        while(l_i <= mid){
            while(p<=right && aux[l_i] > (long)2*aux[p]){
                p++; //keep increasing in right sub-array till condition is satisfied
            }
            result += p - (mid+1);
            //move all possible elems from right sub-array to nums.
            while(r_i<=right && aux[r_i] < aux[l_i]) {
                nums[i++] = aux[r_i++];
            }
            //copy the left elem now
            nums[i++] = aux[l_i++];
        }
        // copy the leftover elems from right sub-array
        while(r_i<=right) {
            nums[i++] = aux[r_i++];
        }
    }
};

//// TLE using BST
class Solution {
  typedef struct Node_ {
        long data, count; //each node maintains num of nodes with higher data than self
        struct Node_ *left, *right;
  }Node;  
public:
       Node *insert(Node *root, long val) {
            if (root == NULL){
                root = new Node;
                root->count = 1; root->data = val;
                root->left = NULL;
                root->right = NULL;
            } else if (val == root->data) {
                root->count++;
            } else if (val < root->data){
                root->left = insert(root->left, val);
            } else {
                root->count++; //increase count of nodes with higher node data than val
                root->right = insert(root->right, val);
            }
            return root;
        }
        int search(Node *root, long val){
            if(root == NULL)
                return 0;
            if(root->data == val)
                return root->count;
            if (val < root->data){
                return root->count + search(root->left, val);
            } else {
                return search(root->right, val);
            }
        }
    int reversePairs(vector<int>& nums) {
        int result=0;
        Node *root=NULL;
        //USE BST...may not be balanced so copmlexity is still o(n^2)
        for(int i=0; i<nums.size(); i++){
            result += search(root, (long)2*nums[i]+1);  // +1 since we need num greater than num[i]*2
            root = insert(root, nums[i]);
        }
        return result;
    }
};