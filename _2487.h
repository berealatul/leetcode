#pragma once
#include "ListNode.h"

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head->next) return head;

        ListNode* buffer = removeNodes(head->next);
        
        if (head->val < buffer->val) {
            delete head;
            return buffer;
        }

        head->next = buffer;
        
        return head;
    }
};