#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int numRabbits(vector<int>& answers) {
    int result= 0;
    vector<int> count(1000);

    for (const int answer : answers) {
      if (count[answer] % (answer + 1) == 0)
        result+= answer + 1;
      ++count[answer];
    }

    return result;
  }
};