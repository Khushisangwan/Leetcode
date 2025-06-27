class Solution {
public:
    bool isKSubsequence(const string& s, const string& x, int k) {
        string t;
        for (int i = 0; i < k; ++i) t += x;
        int j = 0;
        for (char ch : s) {
            if (j < t.size() && ch == t[j]) j++;
        }
        return j == t.size();
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freq;
        for (char ch : s) freq[ch]++;
        
        string valid;
        for (char ch = 'z'; ch >= 'a'; --ch) {
            if (freq[ch] >= k) valid += ch;
        }

        queue<string> q;
        q.push("");
        string res = "";

        while (!q.empty()) {
            string curr = q.front(); q.pop();
            for (char ch : valid) {
                string next = curr + ch;
                if (isKSubsequence(s, next, k)) {
                    if (next.length() > res.length() || (next.length() == res.length() && next > res)) {
                        res = next;
                    }
                    q.push(next);
                }
            }
        }

        return res;
    }
};