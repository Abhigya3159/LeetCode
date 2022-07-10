//SOLUTION 1: WORKS BUT EXCEEDS RUNTIME
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

//SOLUTION 2
