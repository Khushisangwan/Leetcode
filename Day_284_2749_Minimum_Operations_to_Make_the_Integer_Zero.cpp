class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=1;i<=60;i++){
            long long remaining=num1-1LL * i*num2;
            if(remaining<i) continue;

            int ones=0;
            long long temp=remaining;
            while(temp>0){
                ones+=(temp & 1);
                temp>>=1;
            }
            if(ones<=i) return i;
        }
        return -1;

    }
};