/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Heap {
private:
    vector<ListNode *> heap;
public:
    Heap(const vector<ListNode *> &A) {
        heap = A;
        for (int i = A.size() - 1; i >= 0; i--) {
            siftDown(i);
           
        }
    }

    bool empty() {
        return heap.empty();
    }

    void push(ListNode *node) {
        heap.push_back(node);
        siftUp(heap.size() - 1);
    }

    ListNode *top() {
        return heap[0];
    }

    void pop() {
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        siftDown(0);
    }

    void swap(int i, int j) {
        ListNode *tmp = heap[i];
        heap[i] = heap[j];
        heap[j] = tmp;
    }

    void siftUp(int idx) {
        while (idx > 0) {
            int parIdx = (idx - 1) / 2;
            if ((heap[parIdx]->val) < (heap[idx]->val))
                break;
            swap(parIdx, idx);
            idx = parIdx;
        }
    }

    void siftDown(int idx) {
        while (true) {
            int leftIdx = idx * 2 + 1;
            int rightIdx = idx * 2 + 2;
            int swapIdx = idx;

            if (leftIdx < heap.size() && (heap[swapIdx]->val) > (heap[leftIdx]->val))
                swapIdx = leftIdx;
            if (rightIdx < heap.size() && (heap[swapIdx]->val) > (heap[rightIdx]->val))
                swapIdx = rightIdx;

            if (swapIdx == idx)
                break;

            swap(idx, swapIdx);
            idx = swapIdx;
        }
    }
};


ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    Heap heap(A);
    ListNode *res = new ListNode(0);
    ListNode *currRes = res;

    while (!heap.empty()) {
        ListNode *curr = heap.top();
        heap.pop();

        currRes->next = curr;
        currRes = currRes -> next;

        if (curr->next != NULL)
            heap.push(curr->next);
    }

    return res->next;
}