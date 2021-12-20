#include <iostream>
#include <vector>
#include "ListNode.h"
#include "fun.h"

using namespace std;


ListNode* sortList(ListNode* head, ListNode* tail) {
	if (head == nullptr) {
		return head;
	}
	if (head->next == tail) {
		head->next = nullptr;
		return head;
	}
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != nullptr) {//双指针寻找中间点，slow即为链表的中点。
		slow = slow->next;
		fast = fast->next;
		if (fast != nullptr) {
			fast = fast->next;
		}
	}
	return mergeTwoLists(sortList(head, slow), mergeTwoLists(slow, tail));
}

ListNode* sortList(ListNode* head) {
	if (head == nullptr) {
		return head;
	}
	int length = 0;
	ListNode* count = head;
	while (count != nullptr) {
		length++;
		count = count->next;
	}
	int sublength = 1;
	ListNode* prehead = new ListNode(-1, head);
	for (sublength = 1; sublength < length; sublength <<= 1) {
		ListNode* pre = prehead, * curr = prehead->next;
		while (curr != nullptr) {
			ListNode* head1 = curr;
			for (int i = 1; i < sublength && curr->next != nullptr; i++) {
				curr = curr->next;
			}
			ListNode* head2 = curr->next;
			curr->next = nullptr;
			curr = head2;
			for (int i = 1; i < sublength && curr != nullptr && curr->next != nullptr; i++) {//获取head1的for循环中因为while判断了curr是否为nullptr，																					 
				curr = curr->next;															 //但此后又对curr进行了操作，所以此处需要额外判断curr的状态
			}
			ListNode* next = nullptr;
			if (curr != nullptr) {
				next = curr->next;
				curr->next = nullptr;
			}
			ListNode* listed = mergeTwoLists(head1, head2);
			pre->next = listed;
			while (pre->next != nullptr) {
				pre = pre->next;
			}
			curr = next;
		}
	}
	return prehead->next;
}
