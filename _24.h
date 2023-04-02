#pragma once
#include "ListNode.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        head = swap(head);
        head->next->next = swapPairs(head->next->next);

        return head;
    }
private:
    ListNode* swap(ListNode* head) {
        ListNode* buffer = head->next;
        head->next = head->next->next;
        buffer->next = head;
        return buffer;
    }
};