class Solution {
public:
    int maxDistance(vector<int>& A, vector<int>& B) {
        int i = 0, j = 0;

        while (i < A.size() && j < B.size()) {
            if (A[i] > B[j]) i++;
            j++;
        }
        return max(0, j - i - 1);
    }
};