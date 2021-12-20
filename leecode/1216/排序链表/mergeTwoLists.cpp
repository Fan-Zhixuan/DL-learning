#include <iostream>
#include <vector>
#include "ListNode.h"

using namespace std;

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	int p1 = 0, p2 = 0;
	ListNode* prehead = new ListNode(-1);
	ListNode* pre = prehead;
	while (list1 != nullptr && list2 != nullptr) {
		if (list1->val <= list2->val) {
			pre->next = list1;
			list1 = list1->next;
		}
		else {
			pre->next = list2;
			list2 = list2->next;
		}
		pre = pre->next;
	}
	if (list1 == nullptr) {
		pre->next = list2;
	}
	else {
		pre->next = list1;
	}
	return prehead->next;
}