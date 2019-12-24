//Permutation sequence
//Given n and k, return the kth permutation sequence.
class Solution {
    string result;
public:
    string getPermutation(int n, int k) {
        vector<char> numset(n,'1');
        int fact = n; 
        int idx;
        //interval for e.g. for 5 nums:
         /*   1 2 3 4 5
            fact = 5! = 120
            starting with 1 there are 4!=24 sequences
            starting with 2 there are 4!=24 sequences and so on
            So 98th sequence will start with 5
            fact = 120
            fact = 120/5 = 24
            idx = 98/24 = 4th idx from numset which is 5
            k = 98 - (4*24) = 2 
          */
        for(int i=1; i<n; i++){
            fact = fact * i;
            numset[i] = numset[i-1] + 1;    
        }        
        while(n>0){
            fact = fact/n;            
            idx = (k-1)/fact; //to take care of border cases use k-1...e.g 96
            result += numset[idx];
            k = k - (idx * fact);
            numset.erase(numset.begin()+idx);
            n--;
        }
        return result;
    }
};

//NEXT PERMUTATION
//5 3 8 7 6 1      == >   5 6 1 3 7 8
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        //5 3 8 7 6 1
        if(nums.size()==0)
            return;
        for(i=nums.size()-1; i>0; i--){
            if(nums[i] > nums[i-1])
                break;
        }
        if(i==0){
            reverse(nums.begin(), nums.end());
        } else {
            reverse(nums.begin()+i, nums.end());
            for(int k=i; k<nums.size(); k++) {
                if(nums[i-1]<nums[k]) {
                    swap(nums[i-1], nums[k]);
                    break;
                }
            }
        }
    }
};