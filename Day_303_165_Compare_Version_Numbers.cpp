#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int compareVersion(string& v1, string& v2) {
        const int n1=v1.size(), n2=v2.size();
        int x1=0, x2=0; // Current revision numbers being compared
        
        // Iterate through both version strings simultaneously
        for(int i=0, j=0; i<n1 || j<n2; i++, j++){
            // Extract next revision number from v1
            while(i<n1 && v1[i]!='.'){
                x1=10*x1+(v1[i++]-'0');
            }
            // Extract next revision number from v2
            while(j<n2 && v2[j]!='.'){
                x2=10*x2+(v2[j++]-'0');
            }
            
            // Compare current revision numbers
            if (x1<x2) return -1;      // v1 < v2
            else if (x1>x2) return 1;  // v1 > v2
            
            // Reset for next revision comparison
            x1=0;
            x2=0;
        }
        return 0; // Versions are equal
    }
};
