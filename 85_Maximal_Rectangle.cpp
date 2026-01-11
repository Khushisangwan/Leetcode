#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int RectangleArea(vector<int> h) {
        int n =h.size();
        vector<int>r_s(n);
         vector<int>l_s(n);
        stack <int>st;
        for(int i =0;i<n;i++){
            while(!st.empty()&& h[st.top()]>h[i]){
                r_s[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            r_s[st.top()]=n;
            st.pop();
        } 

        for(int i =n-1;i>=0;i--){
            while(!st.empty()&& h[st.top()]>h[i]){
                l_s[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
         while(!st.empty()){
            l_s[st.top()]=-1;
            st.pop();
        }
int ans =0;
        for(int i =0;i<n;i++){
         ans =max(ans,h[i]*(r_s[i]-l_s[i]-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& m) {
        int r=m.size();
        int c=m[0].size();
        int ans =0;
        vector<int>h(c,0);
        for(int i =0;i<r;i++){
            for(int j=0;j<c;j++){
                if(m[i][j]=='0')
                  h[j]=0;
                else
                 h[j]++;
            }
            ans=max(ans,RectangleArea(h));
        }
        return ans;
    }
};