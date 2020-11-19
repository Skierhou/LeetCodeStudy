#pragma once
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    int key;
    ListNode* next;
    ListNode* prev;
    ListNode() : val(0), key(0), next(nullptr), prev(nullptr) {}
    ListNode(int x) : val(x), key(0), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), key(0), next(next), prev(nullptr) {}
    ListNode(int x, ListNode* next, ListNode* prev) : val(x), key(0), next(next), prev(prev) {}

    ListNode(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
    ListNode(int x, int y, ListNode* next, ListNode* prev) : key(x), val(y), next(next), prev(prev) {}

};
