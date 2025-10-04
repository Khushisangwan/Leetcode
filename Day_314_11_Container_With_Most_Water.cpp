class Solution {
public:
    int maxArea(vector<int>& h){
        int n = h.size();
        int i = 0, j = n - 1;
        int ans = 0;
        while(i < j){
            int x = min(h[i], h[j]);
            ans = max(ans, x * (j - i));
            if(h[i] > h[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};