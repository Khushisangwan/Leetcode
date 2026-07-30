class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& n, int k) {
        multiset<int> s;
        vector<int> ans;
        for (int i = 0; i < n.size(); i++) {
            s.insert(n[i]);
            if (i >= k)
                s.erase(s.find(n[i-k]));
            if (i >= k-1)
                ans.push_back(*s.rbegin());
        }
        return ans;
    }
};