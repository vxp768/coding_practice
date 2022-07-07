
//// Using hash of substring instead of sort
vector<int> getHash(string str){
	vector<int> freq(26, 0);
	for(int i=0; i<str.size(); i++){
		freq[str[i]-'a']++;
	}
	return freq;
}
int countOfAnagramSubstring(string str) 
{ 
	int N = str.length(); 

	// To store counts of substrings with given 
	// set of frequencies. map can take vector<int> as key but not unordered_map
	map<vector<int>, int> mp; 
 
	/// O(n^3)
	for (int len=1; len<=N; len++) { 
		for (int i=0; i<=N-len; i++) { 
			vector<int> tmp = getHash(str.substr(i, len)); 
			mp[tmp]++;
		} 
	} 
	// loop over all different freq array and aggregate substring count 
	int result = 0; 
	for (auto it=mp.begin(); it!=mp.end(); it++) 
	{ 
		int freq = it->second; 
		result += ((freq) * (freq-1))/2;   //possible pairs
	} 
	return result; 
} 

//https://www.geeksforgeeks.org/count-total-anagram-substrings/

int countOfAnagramSubstring(string str) 
{ 
	int N = str.length(); 

	// To store counts of substrings with given 
	// set of frequencies. 
	map<string, int> mp; 
 
	for (int len=1; len<=N; len++) { 
		for (int i=0; i<=N-len; i++) { 
			string tmp = str.substr(i, len); 
			sort(tmp.begin(), tmp.end());
			mp[tmp]++; 
		} 
	} 
	// loop over all different freq array and aggregate substring count 
	int result = 0; 
	for (auto it=mp.begin(); it!=mp.end(); it++) 
	{ 
		int freq = it->second; 
		result += ((freq) * (freq-1))/2;   //possible pairs
	} 
	return result; 
} 

// Driver code to test above methods 
int main() 
{ 
	string str = "xyyx"; 
	cout << countOfAnagramSubstring(str) << endl; 
	return 0; 
}

//Hackerrank: Count pair of anagrams
int sherlockAndAnagrams(string s) {
    unordered_map<string, int> mp;
    int count=0;
    for(int len=1; len<=s.size(); len++){
        for(int i=0; i<s.size()-len+1; i++){
            string str = s.substr(i, len);
            sort(str.begin(), str.end());
            if(mp.find(str)==mp.end()){
                mp[str]=1;
            } else {
                count += mp[str];
                mp[str]++;
            }
        }
    }
return count;
}