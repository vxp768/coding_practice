//IF ARRAY ONLY CONTAINS +ve nos
int runningProduct = 1;
for (int n: nums) {
    runningProduct *= n;
}
return runningProduct;

//FOR +ve nos and zeros
int best = INT_MIN;
int runningProduct = 1;
for (int n: nums) {
    // Pick the larger of current number and the result of the multiplication
    runningProduct = max(runningProduct * n, n);   //will reset after zero  ...pick n if runn_prod=0....so new sub array
    // Keep track of the max runningProduct that we find
    best = max(runningProduct, best);
}
return best;

//For +ve, -ve and zeros
//In case of zeros both max and min will reset
//otherwise keep track of products from first number and also from 2nd -ve number
//in case of odd -ve nos ....prod tracked from 2nd -ve nos will help....else prod tracked from first number will help
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Return early if input is empty
        if (nums.empty()) return 0;
		
        int best = INT_MIN;
        // Running products
        int maxProd = 1;
        int minProd = 1;
        
        for (int n: nums) {
            if (n < 0) {
                // Swap max and min
                swap(maxProd, minProd);
            }
            // Reset to current value if smaller or larger than it
            // (intuitively means that we start considering a new sub-array)
            maxProd = max(maxProd*n, n);
            minProd = min(minProd*n, n);
            // Update the best
            best = max(best, maxProd);
        }
        return best;
    }
};
// SIMPLE TWO PASS Solution.....even number of -ve both will have same answer
//                              odd  number of -ve they will have different ans...take max
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int max_so_far = INT_MIN;
        int prod=1;
        for (int i=0; i<nums.size(); i++) {
            prod = prod*nums[i];
            if (max_so_far<prod) {
                max_so_far = prod;
            }
            prod = prod==0?1:prod;
        }
        prod = 1;
        for (int i=nums.size()-1; i>=0; i--) {
            prod = prod*nums[i];
            if (max_so_far<prod) {
                max_so_far = prod;
            }
            prod = prod==0?1:prod;
        } 
        return max_so_far;
    }
};