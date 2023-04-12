#pragma once
#include "ListNode.h"
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* current = nullptr;
        while (list1 && list2) {
            ListNode* buffer = nullptr;
            if (list1->val <= list2->val) {
                buffer = list1;
                list1 = list1->next;
            }
            else {
                buffer = list2;
                list2 = list2->next;
            }
            buffer->next = nullptr;

            if (!current) head = buffer;
            else current->next = buffer;
            current = buffer;
        }
        
        if (list1) {
            if (!current) head = list1;
            else current->next = list1;
        }

        if (list2) {
            if (!current) head = list2;
            else current->next = list2;
        }
        return head;
    }
};