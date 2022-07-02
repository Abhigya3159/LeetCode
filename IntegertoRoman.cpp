//MY SOLUTION
string intToRoman(int num) {
        string romannumeral;
        int rem = 0;
        vector<int> ivec;
        vector<vector<string>> romandigits{{"", "I", "II", "III", "IV", "V",
                            "VI", "VII", "VIII", "IX"}, {"", "X", "XX", "XXX", "XL", "L",
                            "LX", "LXX", "LXXX", "XC"}, {"", "C", "CC", "CCC", "CD", "D",
                            "DC", "DCC", "DCCC", "CM"}, {"", "M", "MM", "MMM"}};
        while (num != 0){
            rem = num%10;
            ivec.push_back(rem);
            num = num/10;
        }
        vector<int> ivec2(ivec.rbegin(), ivec.rend());
            for (int i = 0, j = ivec2.size()-1; i != ivec2.size(), j >= 0 ; ++i, --j){
                romannumeral += romandigits[j][ivec2[i]];
            }
        return romannumeral;
}

//BETTER SOLUTION
string intToRoman(int num) {
    vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    vector<string> roman = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    
    string ans;
    
    for(int i=0;i<values.size();i++){
        while(num){
            if(values[i]>num){
                break;
            }
            else{
                ans+=roman[i];
                num-=values[i];
            }
        }
    }
    return ans;
}
