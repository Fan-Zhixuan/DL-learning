#include <iostream>
#include <vector>
#include <unordered_map>
#include "listnode.h"
#include "remove.h"

using namespace std;



class MyListedList {
public:
    MyListedList() {
        size = 0;
        head = nullptr;
    }

    int get(int index) {
        if (index > size || index < 0) {
            return -1;
        }
        ListNode* node = head;
        for (int i = 0; i < index; i++) {
            node = node->next;
        }
        return node->val;
    }

    void addAtHead(int val) {
        ListNode* tmp = new ListNode(val);
        tmp->next = head;
        head = tmp;
        size++;
    }

    void addAtTail(int val) {
        if (size == 0) {
            head = new ListNode(val);
            size++;
            return;
        }
        ListNode* find = head;
        while (find->next != nullptr) {
            find = find->next;
        }
        ListNode* tmp = new ListNode(val);
        find->next = tmp;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size || index < 0) {
            return;
        }
        ListNode* tmp = new ListNode(val);
        ListNode* left = head;
        for (int i = 0; i < index - 1; i++) {
            left = left->next;
        }
        tmp->next = left->next;
        left->next = tmp;
        size++;
        
    }

    void deleteAtIndex(int index) {
        if (index > size || index < 0 || size == 0) {
            return;
        }
        ListNode* left = head;
        for (int i = 0; i < index-1; i++) {
            left = left->next;
        }
        if (left->next->next == nullptr) {

            left->next = nullptr;
            
        }
        else {
            left->next = left->next->next;
            left->next->next = nullptr;
        }
        size--;
        
    }
    ~MyListedList() {
        ListNode* tmp = head;
        while (head->next != nullptr) {
            tmp = head->next;
            delete[] head;
            head = tmp;
        }
    }
private:
    int size;
    ListNode* head;
};

/**
 * Your MyListedList object will be instantiated and called as such:
 * MyListedList* obj = new MyListedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


int main() {
    MyListedList ListedList = MyListedList();
    ListedList.addAtHead(1);
    ListedList.addAtTail(3);
    ListedList.addAtIndex(1, 2);   //链表变为1-> 2-> 3
    ListedList.get(1);            //返回2
    ListedList.deleteAtIndex(1);  //现在链表是1-> 3
    ListedList.get(1);            //返回3

}