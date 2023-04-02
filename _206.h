#pragma once
#include "ListNode.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* buffer = reverseList(head->next);
        
        head->next->next = head;
        head->next = nullptr;

        return buffer;
    }
};