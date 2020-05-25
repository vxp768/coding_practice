
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