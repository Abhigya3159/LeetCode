class Solution {
public:
    string hundreds(const string &val, const int &num){
        string words;
        vector<string> svec{"", "One", "Two", "Three", "Four", "Five",
                           "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", 
                           "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
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
            int sbscrpt = (num%100)/10; //tens digit
            int sbscrpt2 = (num%100)%10; //ones digit
            int sbscrpt3 = num/100; //hundreds digit
            int sbscrpt4 = num%100; //For case where remainder is greater than 19
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
        int rem;
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
            remainders.push_back(num/1000000); //millions digit
            remainderstrings.push_back(to_string(num/1000000)); //millions
            text = hundreds(remainderstrings[0], remainders[0]);
            int sbscrpt = (num%1000000)/1000, sbscrpt2 = (num%1000000)%1000;
            if ((sbscrpt == 0) && (sbscrpt2 == 0)){
                text = text + " Million";
            }
            else if ((sbscrpt != 0) && (sbscrpt2 == 0)){
                remainders.push_back(sbscrpt); //thousands
                remainderstrings.push_back(to_string(sbscrpt));
                text2 = hundreds(remainderstrings[1], remainders[1]);
                text = text + " Million " + text2 + " Thousand";
            }
            else if ((sbscrpt == 0) && (sbscrpt2 != 0)){
                remainders.push_back(sbscrpt2); //hundreds
                remainderstrings.push_back(to_string(sbscrpt2));
                text3 = hundreds(remainderstrings[1], remainders[1]);
                text = text + " Million " + text3;
            }
            else {
                remainders.push_back(sbscrpt); //thousands
                remainderstrings.push_back(to_string(sbscrpt));
                remainders.push_back(sbscrpt2); //hundreds
                remainderstrings.push_back(to_string(sbscrpt2));
                text2 = hundreds(remainderstrings[1], remainders[1]);
                text3 = hundreds(remainderstrings[2], remainders[2]);
                text = text + " Million " + text2 + " Thousand " + text3;
            }
        } 
        if (val.size() == 10){
            remainders.push_back(num/1000000000); //billions
            remainderstrings.push_back(to_string(num/1000000000));
            text = hundreds(remainderstrings[0], remainders[0]);
            int sbscrpt = (num%1000000000)/1000000; //millions
            int sbscrpt2 = ((num%1000000000)%1000000)/1000; //thousands
            int sbscrpt3 = ((num%1000000000)%1000000)%1000; //hundreds
            if (sbscrpt == 0){
                if ((sbscrpt2 == 0) && (sbscrpt3 == 0)){
                    text = text + " Billion";
                }
                else if ((sbscrpt2 != 0) && (sbscrpt3 == 0)){
                    remainders.push_back(sbscrpt2); //thousands
                    remainderstrings.push_back(to_string(sbscrpt2));
                    text2 = hundreds(remainderstrings[1], remainders[1]);
                    text = text + " Billion " + text2 + " Thousand";
                }
                else if ((sbscrpt2 == 0) && (sbscrpt3 != 0)){
                    remainders.push_back(sbscrpt3); //hundreds
                    remainderstrings.push_back(to_string(sbscrpt3));
                    text3 = hundreds(remainderstrings[1], remainders[1]);
                    text = text + " Billion " + text3;
                }
                else {
                    remainders.push_back(sbscrpt2); //thousands
                    remainderstrings.push_back(to_string(sbscrpt2));
                    remainders.push_back(sbscrpt3); //hundreds
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
                    remainders.push_back(sbscrpt2); //thousands
                    remainderstrings.push_back(to_string(sbscrpt2));
                    text2 = hundreds(remainderstrings[2], remainders[2]);
                    text = text + text4 + " Million " + text2 + " Thousand";
                }
                else if ((sbscrpt2 == 0) && (sbscrpt3 != 0)){
                    remainders.push_back(sbscrpt3); //hundreds
                    remainderstrings.push_back(to_string(sbscrpt3));
                    text3 = hundreds(remainderstrings[2], remainders[2]);
                    text = text + text4 + " Million " + text3;
                }
                else {
                    remainders.push_back(sbscrpt2); //thousands
                    remainderstrings.push_back(to_string(sbscrpt2));
                    remainders.push_back(sbscrpt3); //hundreds
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
