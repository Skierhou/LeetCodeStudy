#include "Q_143.h"
#include <vector>
#include <iostream>

void Q_143::Execute()
{
    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);

    ans_01(root);

    while (root != nullptr)
    {
        cout << root->val << endl;
        root = root->next;
    }
}

void Q_143::ans_01(ListNode* head)
{
    vector<ListNode*> vec;
    ListNode* temp = head;
    while (temp != nullptr)
    {
        vec.push_back(temp);
        temp = temp->next;
    }
    int n = vec.size();
    ListNode* node = nullptr;
    for (int i = 0; i < n / 2; ++i)
    {
        int last = n - i - 1;
        if (last <= i) break;
        node = vec[i]->next;
        vec[i]->next = vec[last];
        vec[last]->next = node;
    }
    if(node != nullptr)
        node->next = nullptr;
}
