#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       // Max heap to store the potential gain from adding a student to each class
       // Tuple format: (gain, current_pass, current_total)
       priority_queue<tuple<double, int, int>> maxHeap;

    // Initialize heap with gain for each class
    for (const vector<int>& c : classes) {
      const int pass = c[0];
      const int total = c[1];
      maxHeap.emplace(extraPassRatio(pass, total), pass, total);
    }

    // Distribute extra students to classes with maximum gain
    for (int i = 0; i < extraStudents; ++i) {
      const auto [_, pass, total] = maxHeap.top();
      maxHeap.pop();
      // Add one student to the class and recalculate gain
      maxHeap.emplace(extraPassRatio(pass + 1, total + 1), pass + 1, total + 1);
    }

    // Calculate the sum of all pass ratios
    double ratioSum = 0;

    while (!maxHeap.empty()) {
      const auto [_, pass, total] = maxHeap.top();
      maxHeap.pop();
      ratioSum += pass / static_cast<double>(total);
    }

    // Return average pass ratio across all classes
    return ratioSum / classes.size();
  }

 private:
  // Calculate the gain in pass ratio when adding one student to a class
  double extraPassRatio(int pass, int total) {
    return (pass + 1) / static_cast<double>(total + 1) -
           pass / static_cast<double>(total);  
    }
};