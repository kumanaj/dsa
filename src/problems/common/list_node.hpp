#pragma once
// LeetCode's singly linked list node, exactly as LeetCode defines it, so solutions paste unchanged.
// Shared by every linked-list problem, which is why it lives outside the per-problem namespaces.
// The helpers below are for tests only.

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// [1,2,3] -> 1 -> 2 -> 3. An empty vector gives nullptr.
inline ListNode* build_list(const std::vector<int>& values) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : values) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

// 1 -> 2 -> 3 -> [1,2,3]. Don't call it on a list with a cycle.
inline std::vector<int> to_vector(ListNode* head) {
    std::vector<int> values;
    for (ListNode* curr = head; curr != nullptr; curr = curr->next) {
        values.push_back(curr->val);
    }
    return values;
}

// Deletes every node. Don't call it on a list with a cycle.
inline void free_list(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}
