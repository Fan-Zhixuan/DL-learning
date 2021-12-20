#include <iostream>
#include <vector>
#include "ListNode.h"
#include "fun.h"

using namespace std;


ListNode* insertionSortList(ListNode* head) {
	if (head == nullptr) {
		return head;
	}
	ListNode* prehead = new ListNode(-1, head);
	ListNode* last = head;
	ListNode* curr = head->next;
	while (curr != nullptr) {
		if (last->val <= curr->val) {
			last = curr;
			curr = last->next;
		}
		else {
			head = prehead;
			last->next = curr->next;
			while (head->next->val<=curr->val) {
				head = head->next;
			}
			curr->next = head->next;
			head->next = curr;
			curr = last->next;
		}
	}
	return prehead->next;
}