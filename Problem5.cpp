class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int wordCount = count(text.begin(), text.end(), ' ')+1; 
        for(int i = 0; i < text.size(); ++i){
            for(int j = 0;  j < brokenLetters.size(); ++j)
                if(text[i] == brokenLetters[j]){
                    --wordCount; 
                    for(; i < text.size() && text[i] != ' '; ++i);
                }      
        } 
        return wordCount;
    }
};
