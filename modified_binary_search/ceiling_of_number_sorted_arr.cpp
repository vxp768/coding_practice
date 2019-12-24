/*
 given sorted array and a val x, find the ceiling of a number.
*/
int main() 
{ 
	int arr[] = {1, 2, 8, 10, 10, 12, 19}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int target = 9; 
    int low=0, high = n-1;
    int index=-1;
    
    while(low<=high) {
     int mid = low + (high-low)/2;
     if(arr[mid] == target) {
       index = mid;
       break;
     }
     if(target < arr[mid]) {
        if(mid-1> low && target > arr[mid-1]) {
           index = mid; break;
        }
        high = mid-1;
     } else {
        if(mid+1<high && target < arr[mid+1]) {
          index = mid; break;
        }
        low = mid+1;
     }
    }
    
    if(index == -1) 
        cout << "Ceiling of " << target << " doesn't exist in array ";
    else
        cout << "ceiling of " << target << " is " << arr[index]; 
    return 0; 
} 
