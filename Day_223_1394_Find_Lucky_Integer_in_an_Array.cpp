class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> map;
        int ans = -1;
        for(int i: arr){
            map[i]++;
        }

        for(int i: arr){
            if(i == map[i]){
                if(i > ans) 
                    ans = i;
            }
        }

        return ans;
    }
};