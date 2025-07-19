class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
         std::sort(folder.begin(), folder.end());
        std::vector<std::string> ans = {folder[0]};

        for (int i = 1; i < folder.size(); ++i) {
            if (folder[i].substr(0, ans.back().size() + 1) != ans.back() + "/") {
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};