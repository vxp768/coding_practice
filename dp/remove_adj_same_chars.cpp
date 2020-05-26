/*
 * Remove same adj chars recursively
 * e.g.:
 * ABCCBCBA ==> ABBCBA ==> ACBA
 */
 
 void remove_adj_same_chars(string str) {
     int len = str.size();
     int i=0, j=0;
     for(i=1; i<len; i++){
        while(str[i] == str[j] && j>=0){
            i++;
            j--;
        }
        str[++j] = str[i];
     }
 }