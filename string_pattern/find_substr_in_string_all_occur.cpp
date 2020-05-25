#include <iostream>
#include <string>
#include <algorithm> 
/*
 *Find all positions of a SubString in given String
 */
void findAllOccurances(vector<size_t> & vec, string data, string toSearch)
{
    size_t pos = data.find(toSearch);                           // Get the first occurrence
    while( pos != string::npos) {                               // Repeat till end is reached
        vec.push_back(pos);
        pos =data.find(toSearch, pos + toSearch.size());        // Get the next occurrence from the current position
    }
}
int main() 
{
    string data = "Hi this is a Sample string, 'iS' is here 3 times";
    vector<size_t> vec;
 
    findAllOccurances(vec, data , "is");                        // Get All occurrences of the 'is' in the vector 'vec'
 
    cout<<"All Index Position of 'is' in given string are,"<<std::endl;
    for(size_t pos : vec)
        std::cout<<pos<<std::endl;
    return 0;
}

/* Efficient solution is to use KMP algo
 *
 */
 https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/