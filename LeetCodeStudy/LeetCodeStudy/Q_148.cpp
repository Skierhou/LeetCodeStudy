#include "Q_148.h"
#include <vector>

void Q_148::Execute()
{
    vector<int> vec{4,19,14,5,-3,1,8,5,11,15};
    ListNode* root = new ListNode(vec[0]);
    ListNode* temp = root;
    for (int i = 1; i < vec.size(); ++i)
    {
        temp->next = new ListNode(vec[i]);
        temp = temp->next;
    }
    root = ans_03(root,nullptr);
}

ListNode* Q_148::ans_01(ListNode* head, ListNode* end)
{
    if (head == nullptr || head == end || head->next == end) return head;

    ListNode* root = head;
    ListNode* node = root;
    int val = root->val;
    while (node != nullptr && node->next != nullptr)
    {
        if (node->next->val <= val)
        {
            ListNode* temp = node->next;
            node->next = node->next->next;
            temp->next = root;
            root = temp;
        }
        else
        {
            node = node->next;
        }
    }
    head->next = ans_01(head->next, nullptr);
    return ans_01(root, head);
}

ListNode* Q_148::ans_02(ListNode* head)
{
    ListNode* pre = new ListNode(0);
    while (head)
    {
        ListNode* p = pre;
        while (p->next && p->next->val <= head->val) p = p->next;
        ListNode* q = head;
        head = head->next;
        q->next = p->next;
        p->next = q;
    }
    return pre->next;
}

ListNode* Q_148::ans_03(ListNode* head, ListNode* tail)
{
    if (head == nullptr)
        return head;
    if (head->next == tail)
    {
        head->next = nullptr;
        return head;
    }
    ListNode* slot = head, * fast = head;
    while (fast != tail)
    {
        slot = slot->next;
        fast = fast->next;
        if (fast != tail)
            fast = fast->next;
    }
    return mergeTwoLists(ans_03(head, slot), ans_03(slot, tail));
}

ListNode* Q_148::mergeTwoLists(ListNode* temp1, ListNode* temp2)
{
    ListNode* dummyHead = new ListNode(0);
    ListNode* temp = dummyHead;
    while (temp1 != nullptr && temp2 != nullptr) {
        if (temp1->val <= temp2->val) {
            temp->next = temp1;
            temp1 = temp1->next;
        }
        else {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    if (temp1 != nullptr) {
        temp->next = temp1;
    }
    else if (temp2 != nullptr) {
        temp->next = temp2;
    }
    return dummyHead->next;
}



