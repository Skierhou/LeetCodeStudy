#include "Q_24.h"
#include <iostream>

void Q_24::Execute()
{
    ListNode* root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);
    root->next->next->next->next->next = new ListNode(6);

    root = ans_01(root);
    while (root != nullptr)
    {
        cout << root->val << endl;
        root = root->next;
    }
}

ListNode* Q_24::ans_01(ListNode* head)
{
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* temp = head->next;
    head->next = ans_01(temp->next);
    temp->next = head;
    return temp;
}
