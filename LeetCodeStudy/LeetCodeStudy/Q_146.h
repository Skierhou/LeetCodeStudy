#pragma once
#include "IQuestion.h"
#include <queue>
#include <unordered_map>
#include <iostream>
#include "Types.h"

using namespace std;

class Q_146:public IQuestion
{
public:
	void Execute() override;


};

class LRUCache {
private:
    unordered_map<int, ListNode*> cache;
    ListNode* head;
    ListNode* tail;
    int curSize;
    int size;

public:
    LRUCache(int _size) :size(_size), curSize(0)
    {
        // 使用伪头部和伪尾部节点
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (!cache.count(key))
        {
            return -1;
        }
        ListNode* temp = cache[key];
        if (head->next != temp)
        {
            temp->prev = head;
            ListNode* p = head->next;
            ListNode* q = temp->next;
            head->next = temp;
            temp->next = p;
            p->prev = temp;
            q->prev = p;
            p->next = q;
        }
        return temp->val;
    }
    void put(int key, int value)
    {
        get(key);
        ListNode* node = head->next;
        if (node != nullptr && node->key == key)
        {
            node->val = value;
        }
        else
        {
            ListNode* node = new ListNode(key, value);
            cache[key] = node;
            addHead(node);
        }
        if (curSize > size)
        {
            removeTail();
        }
    }

    void addHead(ListNode* node)
    {
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        ++curSize;
    }
    void removeTail()
    {
        cache.erase(tail->prev->key);
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
        --curSize;
    }
};

