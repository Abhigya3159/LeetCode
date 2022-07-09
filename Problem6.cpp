/* Problem
Inputs: Number of presses, number of bulbs
4 buttons: Button1 - flip status of all bulbs | Button2 - flip status of even-numbered bulbs | Button3 - flip status of odd-numbered bulbs | 
           Button4 - flip status of bulbs that satisfy 3k + 1, k = 0,1,2...
Initial status: All bulbs are on, counting of bulbs starts at 1
Condition: For each press you may pick any of the four buttons to press
Output: Number of different possible statuses after performing all the button presses
*/

class Solution {
public:
    int flipLights(int n, int presses) {
        int count = 0;
        if (presses == 0) count = 1;
        if (n == 1 && presses > 0) count = 2;
        if (n == 2 && presses > 0) count = (presses > 1) ? 4 : 3;
        else if (n > 2 && presses > 0) count = (presses > 1) ? (presses > 2) ? 8 : 7 : 4;
        return count;
    }
};
