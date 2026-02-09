class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;

            int n = height.size();
            
            vector<int> left(n);
            vector<int> right(n);

            left[0] = height[0];
            for(int i=1; i<n; i++){
                left[i] = max(height[i], left[i-1]);
            }

            right[n-1] = height[n-1];
            for(int i=n-2; i>=0; i--){
                right[i] = max(height[i], right[i+1]);
            }

            int ans=0;
            for(int i=0; i<n; i++){
                ans += min(left[i], right[i]) - height[i];
            }

            return ans;   
    }
};