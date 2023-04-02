#pragma once

class Solution {
public:
    int findTheWinner(int n, int k) {
        if (k == 1) return n;

        ListNode* head = createListNode(createData(n), true);

        while (head != head->next) {
            ListNode* previous = nullptr;

            for (int i = 1; i < k; i++) {
                previous = head;
                head = head->next;
            }

            previous->next = head->next;
            delete head;
            head = previous->next;
        }

        return head->val;
    }
private:
    ListNode* createListNode(vector<int> data, bool circular = false) {
        vector<ListNode*> node;
        for (int i = 0; i < data.size(); i++) {
            node.push_back(new ListNode(data[i]));
            if (i) node[i - 1]->next = node[i];
        }

        if (circular) node.back()->next = node.front();

        return node.front();
    }
    vector<int> createData(int n) {
        vector<int> data;
        for(int i = 1; i <= n; i++) data.push_back(i);
        return data;
    }
};