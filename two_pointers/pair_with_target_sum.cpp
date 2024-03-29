// Returns number of pairs in arr[0..n-1] with sum equal 
// to 'sum'
int getPairsCount(int arr[], int n, int sum) 
{ 
    unordered_map<int, int> mp; 
  
    // Store counts of all elements in map m 
    for (int i=0; i<n; i++) 
        mp[arr[i]]++; 
  
    int twice_count = 0; 
  
    // iterate through each element and increment the 
    // count (Notice that every pair is counted twice) 
    for (int i=0; i<n; i++) 
    { 
        twice_count += mp[sum-arr[i]]; //mp includes all possible pairing 
        //and takes care of repeated ints in arrays
  
        // if (arr[i], arr[i]) pair satisfies the condition, 
        // then we need to ensure that the count is 
        // decreased by one such that the (arr[i], arr[i]) 
        // pair is not considered 
        if (sum - arr[i] == arr[i]) 
            twice_count--; 
    } 
  
    // return the half of twice_count 
    return twice_count/2; 
}