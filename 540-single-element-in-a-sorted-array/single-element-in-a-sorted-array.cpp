class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n=A.size();
        if(n==1){
            return A[0];
        }
        int start=0;
        int end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mid==0 && A[0]!=A[1]){
                return A[mid];
            }
            if(mid==n-1 && A[n-1]!=A[n-2]){
                return A[mid];
            }
            if(A[mid-1]!=A[mid] && A[mid]!=A[mid+1]){
                return A[mid];
            }
            if(mid%2==0){
                if(A[mid-1]==A[mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(A[mid-1]==A[mid]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};