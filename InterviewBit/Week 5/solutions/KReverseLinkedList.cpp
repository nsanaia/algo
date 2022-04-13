#include <bits/stdc++.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    ListNode* res = new ListNode(0);
    ListNode* currRes = res;
    ListNode* curr = A;
    pair<ListNode*, ListNode* > currWindow;
    int currB = 0;

    while (curr != NULL) {
        ListNode* next = curr -> next;
        currB++;

        if (currB == 1) {
            curr -> next = NULL;
            currWindow = {curr, curr};
        } else {
            curr -> next = currWindow.second;
            currWindow.second = curr;
        }

        if (currB == B || next == NULL) {
            currB = 0;
            currRes -> next = currWindow.second;
            currRes = currWindow.first;
        }

        curr = next;
    }

    return res -> next;
}