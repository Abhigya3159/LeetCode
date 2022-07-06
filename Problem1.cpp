int romanToInt(string s) {
        int sum = 0;
        for (auto b = s.begin(); b != s.end(); ++b){
            if (*b == 'I')
                sum += 1;
            if (*b == 'V')
                sum += 5;
            if (*b == 'X')
                sum += 10;
            if (*b == 'L')
                sum += 50;
            if (*b == 'C')
                sum += 100;
            if (*b == 'D')
                sum += 500;
            if (*b == 'M')
                sum += 1000;
        }
        if (s.find("IV") < s.size())
            sum = sum - 2;
        if (s.find("IX") < s.size())
            sum = sum - 2;
        if (s.find("XL") < s.size())
            sum = sum - 20;
        if (s.find("XC") < s.size())
            sum = sum - 20;
        if (s.find("CD") < s.size())
            sum = sum - 200;
        if (s.find("CM") < s.size())
            sum = sum - 200;
        return sum;
}
