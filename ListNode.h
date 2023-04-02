#pragma once
#include <iostream>
#include<vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createListNode(vector<int> data, bool circular = false) {
    vector<ListNode*> node;
    for (int i = 0; i < data.size(); i++) {
        node.push_back(new ListNode(data[i]));
        if (i) node[i - 1]->next = node[i];
    }
    
    if (circular) node.back()->next = node.front();

    return node.front();
}

void printLinkedList(ListNode* head) {
    ListNode* node = head;
    while (node) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

void printCircularLinkedList(ListNode* head) {
    ListNode* node = head;
    do {
        cout << node->val << " ";
        node = node->next;
    } while (node != head);
    cout << endl;
}

ListNode* removeNode(ListNode* node, ListNode* head) {
    if (!node) return head;

    ListNode* buffer = nullptr;

    if (node == head) {
        buffer = head->next;
        delete head;
        return buffer;
    }

    buffer = head;
    while (buffer->next != node) buffer = buffer->next;

    buffer->next = buffer->next->next;
    delete node;
    return head;
}

ListNode* removeNode(ListNode* target, ListNode* head, ListNode* previous) {
    if (!target) return head;
    
    if (!previous) {
        ListNode* buffer = head->next;
        delete target;
        return buffer;
    }

    previous->next = previous->next->next;
    delete target;

    return head;
}

ListNode* deleteHead(ListNode* head) {
    return removeNode(head, head);
}

bool isDecreasing(ListNode* head) {
    ListNode* current = head;
    ListNode* previous = nullptr;
    while (current) {
        if (previous && previous->val < current->val) return false;
        previous = current;
        current = current->next;
    }
    return true;
}