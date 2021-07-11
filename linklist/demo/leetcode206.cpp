class Solution {
public:
    // 递归
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *ret = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ret;
    }
    /* 迭代 
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    */
};