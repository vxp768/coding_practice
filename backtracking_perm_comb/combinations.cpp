//Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
/*
 * n=4, k=2
 * 1,2   1,3  1,4
 * 2,3   2,4
 * 3,4
 */
class Solution {
    
    vector<vector<int>> result;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> part;
        util(part, n, k, 1);
        return result;
    }
    void util(vector<int>& part, int n, int k, int idx)
    {
        if(part.size() == k){
            result.push_back(part);
            return;
        }
        for(int i=idx; i<=n; i++) {
            part.push_back(i);
            util(part, n, k, i+1);
            part.pop_back();
        }       
    }
};