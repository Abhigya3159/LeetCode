class Solution {
public:
    string reverseParentheses(string s) {
        while (s.find("(") != string::npos){
            auto iter = s.find_last_of('(');
            auto iter2 = s.find_first_of(')', iter);
            reverse(s.begin() + iter + 1, s.begin() + iter2);
            s.erase(s.begin() + iter, s.begin() + iter + 1); 
            s.erase(s.begin() + iter2 - 1, s.begin() + iter2);
        }
        return s;
    }
};
