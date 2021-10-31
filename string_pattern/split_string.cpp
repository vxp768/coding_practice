// Using stringstream
int main() 
{ 
      
    string line = "GeeksForGeeks is a must try"; 
      
    vector <string> tokens; 
    stringstream check1(line); 
      
    string intermediate; 
      
    // Tokenizing w.r.t. space ' ' 
    while(getline(check1, intermediate, ' ')) { 
        tokens.push_back(intermediate); 
    } 
    // Printing the token vector 
    for(int i = 0; i < tokens.size(); i++) 
        cout << tokens[i] << '\n'; 
}

//Using strtok
int main() 
{ 
    char str[] = "Geeks-for-Geeks"; 
  
    //Returns first token  
    char *token = strtok(str, "-"); 
  
    //Keep printing tokens while one of the delimiters present in str[]. 
    while (token != NULL) 
    { 
        printf("%s\n", token); 
        token = strtok(NULL, "-"); 
    }
    return 0; 
} 