/* Problem
A binary string is prefix-aligned if all 1s are at the beginning and all 0s at the end e.g., 11000
Input = Vector containing order in which 0s in the binary string must be flipped; vector size = number of 0s in the string
        Example: For vector {3, 2, 1, 4, 5}, the binary string 00000 is prefix-aligned 3 times 
        00100 -> 01100 -> 11100* -> 11110* -> 11111*, (*) denotes prefix-aligned
Output = Number of times binary string is prefix-aligned during the process
*/

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
