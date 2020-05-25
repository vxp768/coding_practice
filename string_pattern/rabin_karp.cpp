/*
 * Find all the substring matching pattern
 * RABIN KARP (using rolling hash)
 *    1. calculate hash of pattern
 *    2. caclulate hash of text for first 'M' char
 *    3. for each new char from text, subtract older char and add new char
 */
 https://leetcode.com/articles/repeated-dna-sequences/
 #define max_char 256
 void rabin_karp_pattern_search (string T, string P, int prime)
 {
     int t_len = T.length();
     int p_len = P.length();
     int h=0;
     int t_hash=0, p_hash=0;
     for(int i = 0; i<patLen-1; i++) {
        h = (h*max_char) % prime;    //calculating h = {d^(M-1)} mod prime
     }
     
     for (int i=0; i<t_len; i++) {
         t_hash = (max_char * t_hash + T[i]) % prime; //modulo prime is to avoid overflow.
         p_hash = (max_char * p_hash + P[i]) % prime;
     }
     
     for(int i=0; i<= t_len - p_len; i++) {
         
         if(p_hash == t_hash) {
             //compare whole string
             for(int j=0; j<p_len; j++) {
                 if(P[j] != T[i-p_len+j]) {
                     break;
                 }
             }
             if(j==p_len) {
                 cout<<"found pattern at "<<i<<endl;
             }
         }
         //find hash for next window
         if(i < t_len - p_len) {
              // p_len-1 .... 2 1 0
             `t_hash = ((t_hash- T[i]*h)*max_char + T[i+p_len]) % prime;
         }
     }
     
 }
