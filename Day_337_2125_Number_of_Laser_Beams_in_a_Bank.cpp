#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Count total laser beams between security devices in a bank.
    // Each '1' is a device; beams are formed between devices on different non-empty rows.
    int numberOfBeams(vector<string>& bank) {
        int prev = 0; // number of devices in the last non-empty row
        int ans = 0;  // accumulated number of beams

        for (int i = 0; i < (int)bank.size(); ++i) {
            int cnt = 0; // number of devices in the current row

            // Count '1's in the current row
            for (char c : bank[i]) {
                if (c == '1') ++cnt;
            }

            // If current row has devices, each connects to every device in previous non-empty row
            if (cnt > 0) {
                ans += cnt * prev;
                prev = cnt; // update previous row count
            }
        }

        return ans;
    }
};