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

//BEST SOLUTION
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int count = 0, previoushighestindex = 0;
        for (int i = 0; i != flips.size(); ++i){
            if (flips[i] > previoushighestindex) previoushighestindex = flips[i];
//Example: If the previous highest index is 3 and the current iterator value is 2(position 3), we must increase count because 1,2 and 3 have all appeared
            if ((i+1) == previoushighestindex) count++;
        }
        return count;
    }
};
