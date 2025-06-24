class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> idx;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == key) idx.push_back(i);
        }

        vector<int> res;

        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<idx.size(); j++){
                // cout << abs(i-j) << " ";
                if(abs(i-idx[j]) <= k){
                    res.push_back(i);
                    break;
                }
            }
        }

        return res;
    }
};