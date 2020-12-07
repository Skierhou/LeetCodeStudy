#pragma once
#include "IQuestion.h"
#include "Types.h"

//在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
//
//示例 1:
//
//输入: 4->2->1->3
//输出 : 1->2->3->4
//示例 2 :
//
//	输入 : -1->5->3->4->0
//	输出 : -1->0->3->4->5
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode-cn.com/problems/sort-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

using namespace std;
class Q_148 : public IQuestion
{
public:
	void Execute() override;

	/*
	解法一：插入排序 O(n^2)
	*/
	ListNode* ans_01(ListNode* head, ListNode* end);

	/*
	解法二：插入排序简化版 O(n^2)
	*/
	ListNode* ans_02(ListNode* head);

	/*
	解法三：自顶向下 归并排序 O(n log(n)) 空间O(log(n))
	1.找到链表的中点，以中点为分界，将链表拆分成两个子链表。寻找链表的中点可以使用快慢指针的做法，
	快指针每次移动 2 步，慢指针每次移动 1 步，当快指针到达链表末尾时，慢指针指向的链表节点即为链表的中点。
	2.对两个子链表分别排序。
    3.将两个排序后的子链表合并，得到完整的排序后的链表。可以使用「21. 合并两个有序链表」的做法，将两个有序的子链表进行合并。
	*/
	ListNode* ans_03(ListNode* head, ListNode* tail);

	/*升序合并两个链表*/
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

	/*
	解法四：自底向上 归并排序 O(n log(n))  空间O(1)
	1.用 subLength 表示每次需要排序的子链表的长度，初始时 subLength=1。
	2.每次将链表拆分成若干个长度为 subLength 的子链表（最后一个子链表的长度可以小于 subLength），
	按照每两个子链表一组进行合并，合并后即可得到若干个长度为 subLength×2 的有序子链表
	（最后一个子链表的长度可以小于 subLength×2）。合并两个子链表仍然使用「21. 合并两个有序链表」的做法。
	3.将 subLength 的值加倍，重复第 2 步，对更长的有序子链表进行合并操作，直到有序子链表的长度大于或等于 length，整个链表排序完毕。

	如何保证每次合并之后得到的子链表都是有序的呢？可以通过数学归纳法证明。
	1.初始时 subLength=1，每个长度为 11 的子链表都是有序的。
	2.如果每个长度为 subLength 的子链表已经有序，合并两个长度为 subLength 的有序子链表，
	得到长度为 subLength×2 的子链表，一定也是有序的。
	3.当最后一个子链表的长度小于 subLength 时，该子链表也是有序的，合并两个有序子链表之后得到的子链表一定也是有序的。
	*/

};

