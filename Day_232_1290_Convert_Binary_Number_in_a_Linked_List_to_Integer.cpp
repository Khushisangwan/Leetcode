#include <bits/stdc++.h>
using namespace std;

// Problem: Convert a binary number represented as a linked list to an integer
// Approach: Traverse the linked list and build the integer by shifting left and adding the current node

// Steps:
// 1. Initialize a result variable to 0.
// 2. Traverse the linked list:
//    - For each node, shift the result left by 1 (equivalent to multiplying by 2).
//    - Add the value of the current node to the result.
// 3. Continue until the end of the linked list is reached.
// 4. Return the result as the final integer value.

// Time Complexity: O(n) where n is the number of nodes in the linked list.
// Space Complexity: O(1) since we are using a constant amount of space.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while(head){
            res = (res << 1) | head->val;
            head = head->next;
        }

        return res;
    }
};