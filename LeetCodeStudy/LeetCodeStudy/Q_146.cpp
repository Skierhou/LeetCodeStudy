#include "Q_146.h"

void Q_146::Execute()
{
	LRUCache *cache = new LRUCache(2 /* �������� */);

	cache->put(1, 1);
	cache->put(2, 2);
	cout << cache->get(1) << endl;       // ����  1
	cache->put(3, 3);    // �ò�����ʹ�ùؼ��� 2 ����
	cout << cache->get(2) << endl;       // ���� -1 (δ�ҵ�)
	cache->put(4, 4);    // �ò�����ʹ�ùؼ��� 1 ����
	cout << cache->get(1) << endl;       // ���� -1 (δ�ҵ�)
	cout << cache->get(3) << endl;       // ����  3
	cout << cache->get(4) << endl;       // ����  4
}
