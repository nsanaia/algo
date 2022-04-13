/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* getFirstHalfEnd(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;

    while (fast -> next != NULL && fast -> next -> next != NULL) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}

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

ListNode* Solution::reorderList(ListNode* A) {
    ListNode* firstHalfEnd = getFirstHalfEnd(A);
    
    ListNode* secondHalf = firstHalfEnd -> next;
    ListNode* reversedSecondHalf = reverse(secondHalf);

    firstHalfEnd -> next = NULL;

    ListNode * res = new ListNode(0);
    ListNode * currRes = res;

    while (A != NULL) {
        currRes -> next = A;
        currRes = currRes -> next;
        A = A -> next;

        if (reversedSecondHalf != NULL) {
            currRes -> next = reversedSecondHalf;
            currRes = currRes -> next;
            reversedSecondHalf = reversedSecondHalf -> next;
        }
    }

    return res -> next;
}
