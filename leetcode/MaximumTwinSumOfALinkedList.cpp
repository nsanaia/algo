/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* getSecondHalf(ListNode* head) {
        auto slow = head;
        auto fast = head;

        while (fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        return slow;
    }
    
    ListNode* getReversed(ListNode* head) {
        auto curr = head;
        ListNode* pre = NULL;
        
        while (curr != NULL) {
            auto currNext = curr -> next;
            
            curr -> next = pre;
            
            pre = curr;
            curr = currNext;
        }

        return pre;
    }
    
    
public:
    
    int pairSum(ListNode* head) {
        auto secondHalf = getSecondHalf(head);
        auto reversedSecondHalf = getReversed(secondHalf);
    
        int res = INT_MIN;
        auto currFirst = head;
        
        for (auto currSecond = reversedSecondHalf; currSecond != NULL; currSecond = currSecond -> next) {
            int currSum = currSecond -> val + currFirst -> val;
            res = max(res, currSum);
            currFirst = currFirst -> next;
        }
        
        return res;
    }
};