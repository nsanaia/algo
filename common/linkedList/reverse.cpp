ListNode* reverse(ListNode* node) {
    ListNode* pre = NULL;
    ListNode* curr = node;

    while (curr != NULL) {
        ListNode* next = curr -> next;

        curr -> next = pre;
        pre = curr;

        curr = next;
    }

    return pre;
}