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
    root = ans_01_sort(root,nullptr);
}

ListNode* Q_148::ans_01(ListNode* head)
{
	return nullptr;
}

ListNode* Q_148::ans_01_sort(ListNode* head, ListNode* end)
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
    head->next = ans_01_sort(head->next, nullptr);
    return ans_01_sort(root, head);
}

