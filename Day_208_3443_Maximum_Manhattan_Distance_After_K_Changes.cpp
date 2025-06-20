#include<bits/stdc++.h>
using namespace std;
// Problem: Maximum Manhattan Distance After K Changes
// Contest: Codeforces - Codeforces Round #344 (Div. 2)
// URL: https://codeforces.com/problemset/problem/344/C

class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int north = 0, south = 0, east = 0, west = 0;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'N') north++;
            else if (c == 'S') south++;
            else if (c == 'E') east++;
            else if (c == 'W') west++;
            
            int x = abs(north - south);
            int y = abs(east - west);
            int MD = x + y;
            int dis = MD + min(2 * k, i + 1 - MD);
            ans = max(ans, dis);
        }
        
        return ans;
    }
};