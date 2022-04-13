#include <bits/stdc++.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


void insert(ListNode* dest, ListNode* node) {
    while (dest -> next != NULL && dest -> next -> val < node -> val) 
        dest = dest -> next;
        
    node -> next = dest -> next;
    dest -> next = node;
}

ListNode* Solution::insertionSortList(ListNode* A) {
    ListNode* res = new ListNode(INT_MIN);

    while (A != NULL) {
        ListNode* ANext = A -> next;
        insert(res, A);
        A = ANext;
    }

    return res -> next;
}
