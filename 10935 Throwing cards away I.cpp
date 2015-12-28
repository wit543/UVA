// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef int valueType;

struct ListNode
{
    valueType val;
    ListNode* next;
    ListNode* prev;
    ListNode(valueType val, ListNode* next=0, ListNode* prev=0)
            : val(val), next(next),prev(prev) {}
};

class LinkedList
{
private:
    ListNode* header=0;
    ListNode* tail;
    void free_list();

public:
    LinkedList();
    ~LinkedList();
    void print_list();
    void insert(valueType x);
    valueType pop();
    void move();

};

LinkedList::LinkedList()
{

}
LinkedList::~LinkedList() {}
void LinkedList::free_list() {
    while(header->val!=0){
        ListNode* temp = header->next;
        delete header;
        header = temp;
    }
}
void LinkedList::print_list()
{
    ListNode* node = header->next;
    while(node != 0) {
        cout << node->val;
        node = node->next;
    }
}

void LinkedList::insert(valueType x) {
    if(header==0) {
        header = new ListNode(x);
        tail=header;
        tail->next=header;
        tail->prev=header;
    }
    else{
        ListNode *newNode = new ListNode(x);
        newNode->next = tail->next;
        newNode->prev = tail;
        tail->next->prev = newNode;
        tail->next = newNode;
        tail = newNode;
    }

}
void LinkedList::move(){
    tail=tail->next;
}
valueType LinkedList::pop() {
    tail->next->prev = tail->prev;
    tail->prev->next = tail->next;
    ListNode *temp = tail;
    tail = tail->prev;
    return temp->val;
}
int main(){
    int a;
    while(true) {
        cin >> a;
        if (a == 0) { break; }
        LinkedList l = *new LinkedList();
        for (int i = 1; i <= a; i++) {
            l.insert(i);
        }
        l.move();
        cout<<"Discarded cards: ";
        if (a > 1){
            for (int i = 1; i < a - 1; i++) {
                cout << l.pop() << ", ";
                l.move();
                l.move();
            }
        cout<<l.pop();
        }
        cout<<endl<<"Remaining card: "<<l.pop()<<endl;
//        l.~LinkedList();

    }
}
