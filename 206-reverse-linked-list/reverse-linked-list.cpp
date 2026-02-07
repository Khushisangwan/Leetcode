class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* temp = curr->next; // Store the next node
            curr->next = prev;            // Reverse the current node's pointer
            prev = curr;                  // Move prev to current node
            curr = temp;                  // Move to the next node
        }
        return prev; // New head of the reversed list
    }
};