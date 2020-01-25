/* Inorder Traversal in an array*/
void inorder(int a[], vector<int> v, int n, int index) {
    // if index is greater or equal to array size (n)
    if(index >= n) 
        return; 
    inorder(a, v, n, 2 * index + 1); 
      
    // push elements in vector 
    v.push_back(a[index]); 
    inorder(a, v, n, 2 * index + 2); 
}