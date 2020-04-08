/*
    Count number of bits set to 1 in any given word/integer

Usage:
 *  determine the size of the intersection or union between two bitsets.
        In such cases, we must first apply a logical operation on pairs of words (AND, OR) and then compute the
        population count of the resulting words. For example, the cardinality of the intersection of the sets A =
        {4, 5, 6, 7} and B = {1, 3, 5, 7} represented by the words 0xF0 and 0xAA can be computed as 
        |A ∩ B| = popcount(0xF0 AND 0xAA) = popcount(0xA0) = 2.

 *  error correction: Hamming weight is Hamming distance, which is the number of differing positions between two strings of identical length. 
                      For two binary strings x and y, this is just the popcount of them XORed together.

*/
//   https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
//   https://arxiv.org/pdf/1611.07612.pdf

// O(n)
unsigned int countSetBits(unsigned int n) { 
    unsigned int count = 0; 
    while (n) { 
        count += n & 1;
        n >>= 1;
    }
    return count;
}

/*
 * Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) including the rightmost set bit.
for example :
            10 in binary is 00001010
            9 in binary is 00001001
            8 in binary is 00001000
            7 in binary is 00000111
So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)), we unset the rightmost set bit.
 If we do n & (n-1) in a loop and count the no of times loop executes we get the set bit count.
*/
// O(n)
unsigned int countSetBits(int n) { 
        unsigned int count = 0; 
        while (n) { 
            n &= (n - 1); 
            count++; 
        } 
        return count; 
}

//Use builtin functions supported on CPU
  __builtin_popcount(n)
  

// Use lookup table
// Function to initialise the lookup table  
void initialize() {  
    // To initially generate the  table algorithmically  
    BitsSetTable256[0] = 0;  
    for (int i = 0; i < 256; i++) {  
        BitsSetTable256[i] = (i & 1) +  
        BitsSetTable256[i / 2];  
    }  
}
// Function to return the count of set bits in n  
int countSetBits(int n) {  
    return (BitsSetTable256[n & 0xff] +  
            BitsSetTable256[(n >> 8) & 0xff] +  
            BitsSetTable256[(n >> 16) & 0xff] +  
            BitsSetTable256[n >> 24]);  
}

// 4-bit nibble lookup table
int num_to_bits[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 
                        1, 2, 2, 3, 2, 3, 3, 4 }; 
  
/* Recursively get nibble of a given number and map them in the array */
unsigned int countSetBitsRec(unsigned int num) 
{ 
    int nibble = 0; 
    if (0 == num) 
        return num_to_bits[0]; 
    // Find last nibble 
    nibble = num & 0xf; 
    //Use pre-stored values to find count in last nibble plus recursively add 
    //remaining nibbles.
    return num_to_bits[nibble] + countSetBitsRec(num >> 4); 
}


// FIND next power of 2
unsigned int nextPowerOf2(unsigned int n)  {  
    unsigned count = 0;  
    // First n in the below condition is for the case where n is 0. if already power of 2, return.  
    if (n && !(n & (n - 1)))  
        return n;  
    while( n != 0)  {     //find post of leftmost set bit.
        n >>= 1;          // count will be 1 more than that pos.
        count += 1;  
    }  
    return 1 << count;
}

unsigned int nextPowerOf2(unsigned int n) { 
    n--;                //to take care of num already power of 2
    //Set all bits after the leftmost set bit.
    n |= n >> 1;        //set 1 bit after left_pos...so now two left_most bits are set
    n |= n >> 2;        //after this oper 4 left_most bits are set
    n |= n >> 4;        //after this oper 8 left_most bits are set
    n |= n >> 8;        //after this oper 16 left_most bits are set
    n |= n >> 16;       // all remaining bits after left most bit are set
    n++; 
    return n; 
}