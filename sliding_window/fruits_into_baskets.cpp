/*
In a row of trees, the i-th tree produces fruit with type tree[i].

You start at any tree of your choice, then repeatedly perform the following steps:

Add one piece of fruit from this tree to your baskets.  If you cannot, stop.
Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.

 Each basket can have only 1 type of fruit. Tree types repeat.
*/

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        //this is like biggest sub array with 2 distinct integers
        unordered_map<int, int> mp;
        int left=0;
        int max_len=INT_MIN;
        int i;
        for(i=0; i<tree.size(); i++){
            mp[tree[i]]++;
            if(mp.size()<=2){
                max_len = max(max_len, i-left+1);
                continue;
            }
            while(mp.size()>2) {
                mp[tree[left]]--;
                if(mp[tree[left]]==0)
                    mp.erase(tree[left]);
                left++;
            }
        }
        return max_len;
    }
};