string intToRoman(int num) {
        string romannumeral;
        int rem = 0, cnt = 0;
        list<int> ilst;
        while (num != 0){
            rem = num%10;
            ilst.push_front(rem*pow(10, cnt));
            num = num/10;
            cnt++;
        }
        for (auto b = ilst.begin(); b != ilst.end(); ++b){
            if (*b == 1) romannumeral += "I";
            if (*b == 2) romannumeral += "II";
            if (*b == 3) romannumeral += "III";
            if (*b == 4) romannumeral += "IV";
            if (*b == 5) romannumeral += "V";
            if (*b == 6) romannumeral += "VI";
            if (*b == 7) romannumeral += "VII";
            if (*b == 8) romannumeral += "VIII";
            if (*b == 9) romannumeral += "IX";
            if (*b == 10) romannumeral += "X";
            if (*b == 20) romannumeral += "XX";
            if (*b == 30) romannumeral += "XXX";
            if (*b == 40) romannumeral += "XL";
            if (*b == 50) romannumeral += "L";
            if (*b == 60) romannumeral += "LX";
            if (*b == 70) romannumeral += "LXX";
            if (*b == 80) romannumeral += "LXXX";
            if (*b == 90) romannumeral += "XC";
            if (*b == 100) romannumeral += "C";
            if (*b == 200) romannumeral += "CC";
            if (*b == 300) romannumeral += "CCC";
            if (*b == 400) romannumeral += "CD";
            if (*b == 500) romannumeral += "D";
            if (*b == 600) romannumeral += "DC";
            if (*b == 700) romannumeral += "DCC";
            if (*b == 800) romannumeral += "DCCC";
            if (*b == 900) romannumeral += "CM";
            if (*b == 1000) romannumeral += "M";
            if (*b == 2000) romannumeral += "MM";
            if (*b == 3000) romannumeral += "MMM";
        }
        if (ilst.size() == 4){
            
        }
        return romannumeral;
}


class Solution {
public:
    string intToRoman(int num) {
        string romannumeral;
        int rem = 0, cnt = 0;
        vector<int> ivec;
        /*vector<string> ones{"I", "II", "III", "IV", "V"
                            "VI", "VII", "VIII", "IX"};
        vector<string> tens{"X", "XX", "XXX", "XL", "L"
                            "LX", "LXX", "LXXX", "XC"};
        vector<string> hundreds{"C", "CC", "CCC", "CD", "D"
                            "DC", "DCC", "DCCC", "CM"};
        vector<string> thousands{"M", "MM", "MMM" };*/
        string romandigits[4][9] = {{"I", "II", "III", "IV", "V"
                            "VI", "VII", "VIII", "IX"}, {"X", "XX", "XXX", "XL", "L"
                            "LX", "LXX", "LXXX", "XC"}, {"C", "CC", "CCC", "CD", "D"
                            "DC", "DCC", "DCCC", "CM"}, {"M", "MM", "MMM" }};
        while (num != 0){
            rem = num%10;
            ivec.push_back(rem);
            num = num/10;
            cnt++;
        }
        romannumeral += romandigits[0][ivec[0]];
        auto p = romannumeral.begin();
        if (ivec.size() > 1){
            for (int i = 1; i != ivec.size(); ++i){
                romannumeral.insert(p, romandigits[i][ivec[i]]);
            }
        }
        return romannumeral;
    }
};
