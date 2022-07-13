/* Problem
Input: number of bulbs n
Initial condition: All bulbs are off
Round 1: All bulbs on
Round 2: Toggle every second bulb
Round 3: Toggle every third bulb
Round i: Toggle every ith bulb
Output: Number of bulbs on at the end
*/

//SOLUTION 1: EXCEEDS RUNTIME
class Solution {
public:
    int bulbSwitch(int n) {
        vector<int> bulbs;
        int count = 0;
        if (n == 0) count = 0;
        else {
            for (int i = 0; i != n; ++i) bulbs.push_back(0);
                for (int round = 0; round != n; ++round){
                    for (int i = 0; i != n; ++i){
                        if (round+1 == 1) bulbs[i] = 1;
                        else if ((i+1)%(round+1)==0) bulbs[i] = (bulbs[i] == 0) ? 1 : 0;
                    }
                }
                for (int i = 0; i != n; ++i){
                    if (bulbs[i] == 1) ++count;
                }
        }
        return count;
    }
};

//SOLUTION 2: EXCEEDS RUNTIME
//Bulbs with even number of factors excluding 1 will be on, e.g., For 10 bulbs, bulb 1(0 factors greaters than 1), bulb 4(Two factors (2 and 4) greater than 1) 
//and bulb 9(Two factors (3 and 9) greater than 1) will be on
class Solution {
public:
    int bulbSwitch(int n) {
        int count = 0;
        for (int i = 1; i <= n; ++i){
            int numberoffactors = 0;
            for (int j = 2; j <= i; ++j){
                if (i%j == 0) ++numberoffactors;
            }
            if (numberoffactors%2 == 0) ++count;
        }
        return count;
    }
};

//SOLUTION: BY OBSERVATION
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
