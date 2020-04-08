


int i = 0, binary_a[SIZE] = { 0 }; 
int a;
while (a > 0) { 
    binary_a[i] = a % 2; 
    a /= 2; 
    i++; 
} 