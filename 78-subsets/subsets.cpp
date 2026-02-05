class Solution {
public:
    void findSubsets(int i, vector<int>& nums,
                     vector<int>& temp,
                     vector<vector<int>>& ans) {
        
        // Base case
        if(i == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Include current element
        temp.push_back(nums[i]);
        findSubsets(i + 1, nums, temp, ans);

        // Exclude current element
        temp.pop_back();
        findSubsets(i + 1, nums, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        findSubsets(0, nums, temp, ans);
        return ans;

    }
};
