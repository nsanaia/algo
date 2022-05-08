/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
 */

struct Context {
    ListNode* curr;
};

int getLen(ListNode* A);
TreeNode* sortedListToBSTHelper(int start, int end, Context& context);


TreeNode* Solution::sortedListToBST(ListNode* A) {
    auto len = getLen(A);
    Context context{A};
    return sortedListToBSTHelper(0, len - 1, context);
}

int getLen(ListNode* A) {
    int res = 0;
    for (ListNode* curr = A; curr != NULL; curr = curr -> next)
        res++;
    return res;
}

TreeNode* sortedListToBSTHelper(int start, int end, Context& context) {
    if (start > end) {
        return NULL;
    }

    int mid = (start + end) / 2;
    TreeNode* leftRes = sortedListToBSTHelper(start, mid - 1, context);

    TreeNode* res = new TreeNode(context.curr -> val);
    res -> left = leftRes;

    context.curr =  context.curr -> next;

    res -> right = sortedListToBSTHelper(mid + 1, end, context);

    return res;
}