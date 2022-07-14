/* Problem
You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an index i of nums for which there exists at least one index j 
such that |i - j| <= k and nums[j] == key.
Return a list of all k-distant indices sorted in increasing order.
*/

//MY SOLUTION
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> index;
        int sz = nums.size();
        for (int i = 0; i != sz; ++i){
            if (nums[i] == key){
                for (int j=i-k; j <=i+k; ++j) if (j>=0 && j<sz) index.insert(j);
            }
        }
        vector<int> indexes(index.begin(), index.end());
        return indexes;
    }
};
