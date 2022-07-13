/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "". 
Example: Input = ["flow", "flower", "flight"] | Output = "fl"
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min = strs[0].size(), count = 0, prefixcount = 0, len = strs.size();
        string prefixstring;
        for (int i = 1; i != len; ++i) if (strs[i].size() < min) min = strs[i].size();
        if (min != 0 && len != 1){
            for (int j = 0; j != min; ++j){
                for (int i = 0; i != len-1; ++i){ 
                    if(strs[i][j] == strs[i+1][j]) ++count;
                    else break;
                }
                if (count == len-1){
                    ++prefixcount;
                    count = 0;
                } 
                else break;
            }
            prefixstring = strs[0].substr(0, prefixcount);
        }
        else if(min != 0 && len == 1) prefixstring = strs[0];
        return prefixstring;
    }
};
