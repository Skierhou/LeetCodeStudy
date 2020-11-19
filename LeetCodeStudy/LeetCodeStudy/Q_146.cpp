#include "Q_146.h"

void Q_146::Execute()
{
	LRUCache *cache = new LRUCache(2 /* 缓存容量 */);

	cache->put(1, 1);
	cache->put(2, 2);
	cout << cache->get(1) << endl;       // 返回  1
	cache->put(3, 3);    // 该操作会使得关键字 2 作废
	cout << cache->get(2) << endl;       // 返回 -1 (未找到)
	cache->put(4, 4);    // 该操作会使得关键字 1 作废
	cout << cache->get(1) << endl;       // 返回 -1 (未找到)
	cout << cache->get(3) << endl;       // 返回  3
	cout << cache->get(4) << endl;       // 返回  4
}
