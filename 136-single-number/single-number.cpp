class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int number = nums[i];
            int count = 0;
            for(int j=0;j<nums.size();j++){
                if(nums[j] == number){
                    count++;
                }
            }
            if(count == 1){
                return number;
            }
        }
        return -1;
        
    }
};