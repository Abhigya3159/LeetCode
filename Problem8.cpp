//SOLUTION 1: RUNTIME EXCEEDED
class Solution {
public:
    bool isprefixaligned(const string& s){
        string s_sorted(s.begin(), s.end()); 
        sort(s_sorted.begin(), s_sorted.end());
        reverse(s_sorted.begin(), s_sorted.end());
        return s == s_sorted;
    }
    int numTimesAllBlue(vector<int>& flips) {
        string s;
        int count = 0;
        for (int i = 0; i < flips.size(); ++i){
            s += '0';
        }
        for (int i = 0; i != flips.size(); ++i){
            s[flips[i]-1] = '1';
            if (isprefixaligned(s)) ++count;
        }
        return count;
    }
};
