class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for(char c: s){
            if(c=='a' || c=='e'|| c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                vowels.push_back(c);
            }
        }
        sort(vowels.begin(), vowels.end());
        int i = 0, j= 0;
        while(i<s.size() && j<vowels.size()){
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E'|| s[i]=='I' || s[i]=='O' || s[i]=='U'){
                s[i] = vowels[j];
                j++;
            }
            i++;
        }
        return s;
    }
};