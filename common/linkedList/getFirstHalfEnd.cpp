ListNode* getFirstHalfEnd(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;

    while (fast -> next != NULL && fast -> next -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}