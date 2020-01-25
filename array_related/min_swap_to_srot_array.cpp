
/* Array numbers are consecutive numbers 1...n
 * Any numbers correct position is idx = "num -1"
 * 0 1 2 3 4:   idx
 * 5 3 1 4 2:   num
 */
 //hackerrank
int minimumSwaps(vector<int> arr) {
    int swaps=0;
    for(int i=0; i<arr.size(); i++){
        while(arr[i] != i+1) {
            swap(arr[i], arr[arr[i]-1]);
            swaps++;
        }
    }
return swaps;
}

/* Array numbers are any N numbers */
int findMinSwap(int arr[] , int n) 
{  
    vector<pair<int,int>> vec(n); 
    int swaps=0;
    for(int i=0;i<n;i++) 
    { 
        vec[i].first=arr[i]; 
        vec[i].second=i; 
    } 
    // Sort the vector w.r.t the first element of pair 
    sort(vec.begin(),vec.end());
    for(int i=0;i<n;i++) 
    { 
        // swap until the correct index matches 
        while(vec[i].second != i) {
            // swap with its respective index 
            swap(vec[i].first,vec[vec[i].second].first); 
            swap(vec[i].second,vec[vec[i].second].second); 
            // each swap makes one element move to its correct index
            swaps++; 
        }
    } 
    return swaps; 
} 

/* Minimum swaps required to convert binary tree to binary search */
/*  The idea is to use the fact that inorder traversal of Binary Search Tree is in increasing order of their value.
 *  So, find the inorder traversal of the Binary Tree and store it in the array and try to sort the array. 
 *  The minimum number of swap required to get the array sorted will be the answer.
 */