#pragma once
#include <iostream>
#include <vector>
#include "ListNode.h"
using namespace std;

class Solution {
    void mergeSort(vector<ListNode*>& list) {
        if (list.size() < 2) return;

        auto middle = list.size() / 2;

        vector<ListNode*> left(middle);
        for (int i = 0; i < middle; i++) left[i] = list[i];

        vector<ListNode*> right(list.size() - middle);
        for (int i = middle; i < list.size(); i++) right[i - middle] = list[i];

        mergeSort(left);
        mergeSort(right);

        merge(left, right, list);
    }

    void merge(vector<ListNode*>& left, vector<ListNode*>& right, vector<ListNode*>& list) {
        int i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i]->val < right[j]->val) list[k++] = left[i++];
            else list[k++] = right[j++];
        }

        while (i < left.size()) list[k++] = left[i++];
        while (j < right.size()) list[k++] = right[j++];
    }

    void returnList(ListNode* head, vector<ListNode*>& list) {
        while (head) {
            list.push_back(head);
            head = head->next;
        }
    }

    ListNode* linkMergedNode(vector<ListNode*>& list) {
        for (int i = 0; i < list.size() - 1; i++) {
            list[i]->next = list[i + 1];
        }
        list.back()->next = nullptr;
        return list[0];
    }
    
public:
    ListNode* sortList(ListNode* head) {
        vector<ListNode*> list;
        returnList(head, list);
        mergeSort(list);
        return linkMergedNode(list);
    }

    //--- test function----

    ListNode* populateNode(vector<int>& data) {
        ListNode* root = nullptr;
        ListNode* buffer = nullptr;
        for (auto& val : data) {
            if (!root) {
                root = buffer = new ListNode(val);
                continue;
            }
            buffer->next = new ListNode(val);
            buffer = buffer->next;
        }
        return root;
    }

    void printNode(ListNode* root) {
        while (root) {
            cout << root->val << " ";
            root = root->next;
        }
    }

    void print(vector<ListNode*>& list) {
        for (auto& node : list) cout << node->val << " ";
        cout << endl;
    }
};