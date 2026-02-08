class Solution {
public:
    void solve(int i, string digits, string temp,
               vector<string>& ans,
               vector<string>& map) {

        // Base case
        if(i == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string letters = map[digits[i] - '0'];

        for(char ch : letters) {
            solve(i + 1, digits, temp + ch, ans, map);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits == "") return ans;

        vector<string> map = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solve(0, digits, "", ans, map);
        return ans;
    }
};
