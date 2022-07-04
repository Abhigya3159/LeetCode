//MY SOLUTION
class Solution {
public:
    string hundreds(const string &val, const int &num){
        string words;
        vector<string> svec{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                           "Seventeen", "Eighteen", "Nineteen"};
        vector<string> svec2{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        if (val.size() == 1){
            if (num == 0) words = "Zero";
            else words = svec[num];
        }
        if (val.size() == 2){
            if (num > 9 && num < 20)
                words = svec[num];
            else if (num%10) words = words + svec2[num/10] + " " + svec[num%10];
            else words = words + svec2[num/10];
        }
        if (val.size() == 3){
            int sbscrpt = (num%100)/10, sbscrpt2 = (num%100)%10, sbscrpt3 = num/100, sbscrpt4 = num%100; 
            if (sbscrpt == 0 && sbscrpt2 == 0 && sbscrpt3 == 0 && sbscrpt4 == 0) words += "";
            else if (sbscrpt == 0 && sbscrpt2 != 0) words = words + svec[sbscrpt3] + " Hundred " + svec[sbscrpt2];
            else if (sbscrpt != 0 && sbscrpt2 == 0) words = words + svec[sbscrpt3] + " Hundred " + svec2[sbscrpt];
            else if (sbscrpt == 0 && sbscrpt2 == 0) words = words + svec[sbscrpt3] + " Hundred";
            else if (sbscrpt != 0 && sbscrpt2 != 0 && sbscrpt4 > 19) words = words + svec[sbscrpt3] + " Hundred " + svec2[sbscrpt] + " " + svec[sbscrpt2];
            else words = words + svec[sbscrpt3] + " Hundred " + svec[sbscrpt4];
        }
        return words;
    }
    
    string numberToWords(int num) {
        string val = to_string(num), text, text2, text3, text4;
        vector<int> remainders;
        vector<string> remainderstrings;
        if (val.size() <= 3) text = hundreds(val, num);
        if (val.size() > 3 && val.size() < 7){
            remainders.push_back(num/1000); 
            remainderstrings.push_back(to_string(num/1000)); 
            int sbscrpt = num%1000;
            if (sbscrpt != 0){
                remainders.push_back(sbscrpt); 
                remainderstrings.push_back(to_string(sbscrpt));
                text = hundreds(remainderstrings[0], remainders[0]);
                text2 = hundreds(remainderstrings[1], remainders[1]);
                text = text + " Thousand " + text2;
            }
            else {
                text = hundreds(remainderstrings[0], remainders[0]);
                text = text + " Thousand";
            }
        }
        if (val.size() >= 7 && val.size() < 10){
            remainders.push_back(num/1000000);
            remainderstrings.push_back(to_string(num/1000000)); 
            text = hundreds(remainderstrings[0], remainders[0]);
            int sbscrpt = (num%1000000)/1000, sbscrpt2 = (num%1000000)%1000;
            if ((sbscrpt == 0) && (sbscrpt2 == 0)){
                text = text + " Million";
            }
            else if ((sbscrpt != 0) && (sbscrpt2 == 0)){
                remainders.push_back(sbscrpt); 
                remainderstrings.push_back(to_string(sbscrpt));
                text2 = hundreds(remainderstrings[1], remainders[1]);
                text = text + " Million " + text2 + " Thousand";
            }
            else if ((sbscrpt == 0) && (sbscrpt2 != 0)){
                remainders.push_back(sbscrpt2); 
                remainderstrings.push_back(to_string(sbscrpt2));
                text3 = hundreds(remainderstrings[1], remainders[1]);
                text = text + " Million " + text3;
            }
            else {
                remainders.push_back(sbscrpt); 
                remainderstrings.push_back(to_string(sbscrpt));
                remainders.push_back(sbscrpt2);
                remainderstrings.push_back(to_string(sbscrpt2));
                text2 = hundreds(remainderstrings[1], remainders[1]);
                text3 = hundreds(remainderstrings[2], remainders[2]);
                text = text + " Million " + text2 + " Thousand " + text3;
            }
        } 
        if (val.size() == 10){
            remainders.push_back(num/1000000000); 
            remainderstrings.push_back(to_string(num/1000000000));
            text = hundreds(remainderstrings[0], remainders[0]);
            int sbscrpt = (num%1000000000)/1000000, sbscrpt2 = ((num%1000000000)%1000000)/1000, sbscrpt3 = ((num%1000000000)%1000000)%1000; 
            if (sbscrpt == 0){
                if ((sbscrpt2 == 0) && (sbscrpt3 == 0)){
                    text = text + " Billion";
                }
                else if ((sbscrpt2 != 0) && (sbscrpt3 == 0)){
                    remainders.push_back(sbscrpt2); 
                    remainderstrings.push_back(to_string(sbscrpt2));
                    text2 = hundreds(remainderstrings[1], remainders[1]);
                    text = text + " Billion " + text2 + " Thousand";
                }
                else if ((sbscrpt2 == 0) && (sbscrpt3 != 0)){
                    remainders.push_back(sbscrpt3); 
                    remainderstrings.push_back(to_string(sbscrpt3));
                    text3 = hundreds(remainderstrings[1], remainders[1]);
                    text = text + " Billion " + text3;
                }
                else {
                    remainders.push_back(sbscrpt2); 
                    remainderstrings.push_back(to_string(sbscrpt2));
                    remainders.push_back(sbscrpt3); 
                    remainderstrings.push_back(to_string(sbscrpt3));
                    text2 = hundreds(remainderstrings[1], remainders[1]);
                    text3 = hundreds(remainderstrings[2], remainders[2]);
                    text = text + " Billion " + text2 + " Thousand " + text3;
                }
            }
            if (sbscrpt != 0){
                remainders.push_back(sbscrpt);
                remainderstrings.push_back(to_string(sbscrpt));
                text4 = hundreds(remainderstrings[1], remainders[1]);
                text = text + " Billion ";
                if ((sbscrpt2 == 0) && (sbscrpt3 == 0)){
                    text = text + text4 + " Million";
                }
                else if ((sbscrpt2 != 0) && (sbscrpt3 == 0)){
                    remainders.push_back(sbscrpt2); 
                    remainderstrings.push_back(to_string(sbscrpt2));
                    text2 = hundreds(remainderstrings[2], remainders[2]);
                    text = text + text4 + " Million " + text2 + " Thousand";
                }
                else if ((sbscrpt2 == 0) && (sbscrpt3 != 0)){
                    remainders.push_back(sbscrpt3); 
                    remainderstrings.push_back(to_string(sbscrpt3));
                    text3 = hundreds(remainderstrings[2], remainders[2]);
                    text = text + text4 + " Million " + text3;
                }
                else {
                    remainders.push_back(sbscrpt2); 
                    remainderstrings.push_back(to_string(sbscrpt2));
                    remainders.push_back(sbscrpt3); 
                    remainderstrings.push_back(to_string(sbscrpt3));
                    text2 = hundreds(remainderstrings[2], remainders[2]);
                    text3 = hundreds(remainderstrings[3], remainders[3]);
                    text = text + text4 + " Million " + text2 + " Thousand " + text3;
                }
            }
        }
        return text;
    }
};

//BEST SOLUTION
class Solution {
public:
    string numberToWords(int num) {
        string w1[] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine"};
        string w2[] = {" Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen" };
        string w3[] = {"",  "",  " Twen", " Thir", " For", " Fif", " Six", " Seven", " Eigh", " Nine" };
        string e[] = {"", " Thousand", " Million", " Billion"};
        
        std::string s; int k=0;
        while(num) {
            std::string sub;
            auto s4=num%1000, s3=s4/100, s2=s4%100; //Example 123456: s4=456, s3=4, s2=56
            if(s4) s.insert(0, e[k]); 
            if(s3) sub += w1[s3] + " Hundred";
            if(s2) sub += s2<20? (s2<10? w1[s2%10]: w2[s2%10]): w3[s2/10%10]+"ty"+w1[s2%10];
            s.insert(0, sub);
            num /= 1000;
            k++;
        }
        
        return s.size()? std::string(s.begin()+1, s.end()): "Zero";
    }
};
