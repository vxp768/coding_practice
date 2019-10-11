/*
arr1 = 3, 5, 10  , m = 3
arr2 = 4, 6, 9  , n = 3
 i = 2, j = 1                  i and j are partiotioning the array and are not the array index
 i+j = m-i + n-j
 ==> i+j = (m+n)/2
  
arr1 = 3, 5, 10  , m = 3
arr2 = 4, 6      , n = 2
 i = 1, j = 1
 i+j = m-i + n-j
 ==> i+j = (m+n)/2   this will result in 2 and 2 on each side
  Hence for odd case add 1 to m+n

 i+j = m-i + n-j + 1
 ==> i+j = (m+n+1)/2
 
  Run binary search on the partition size on smaller array

*/