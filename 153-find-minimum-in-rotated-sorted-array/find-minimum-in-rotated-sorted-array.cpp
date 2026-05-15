class Solution {
public:
    int findMin(vector<int>& nums) {
        int min=INT_MAX;
        int l=0;
        int h=nums.size()-1;
        for(int i=0;i<=h;i++){
            if(nums[i]<min){
                min=nums[i];
            }
        }
        return min;
    }
};