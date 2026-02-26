class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[](int& a,int &b)
        {
            int n=__builtin_popcount(a),m=__builtin_popcount(b);
            if(n==m) return a<b;
            return n<m;
        });
        return arr;
    }
};