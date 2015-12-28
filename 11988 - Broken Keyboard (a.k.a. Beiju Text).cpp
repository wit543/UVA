// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

typedef char valueType;

struct ListNode
{
    valueType val;
    ListNode* next;

    ListNode(valueType val, ListNode* next=0)
            : val(val), next(next) {}
};

class LinkedList
{
private:
    ListNode* header;
    ListNode* tail;
    ListNode* current;
    bool front=false;
    void free_list();


public:
    LinkedList();
    ~LinkedList();
    void print_list();
    void insert_front(valueType x);
    void append(valueType x);
    void home();
    void end();
};

LinkedList::LinkedList()
{
    header = new ListNode(0);
    tail = header;
    current = header;
}
LinkedList::~LinkedList() {free_list(); }
void LinkedList::print_list()
{
    ListNode* node = header->next;
    while(node != 0) {
        cout << node->val;
        node = node->next;
    }
}
void LinkedList::append(valueType x)
{
//    cout<<x<<endl;
    ListNode* newList = new ListNode(x);
    newList->next=current->next;
    current->next = newList;
    current=newList;
    if(!front){
        tail=current;
    }

}
void LinkedList::free_list() {
    while(header->val!=0){
        ListNode* temp = header->next;
        delete header;
        header = temp;
    }
}
void LinkedList::insert_front(valueType x)
{

    ListNode* newList = new ListNode(x);
    newList->next = header->next;
    if(header->next ==0){
        tail = newList;
    }
    header->next = newList;

}
void LinkedList::home(){
    current = header;
    front = true;
}
void LinkedList::end(){
    current = tail;
    front =false;
}

int main(){
    while(!cin.eof()){
        string a;
        cin>>a;
        if(cin.eof()){break;}
        LinkedList l;
        for(int i=0;i<=a.size();i++) {
            if (i>=a.size()) {
                l.print_list();
                cout<<"\n";
                l = *new LinkedList();
            }
            else {
                if (a.at(i) == '[') {
                    l.home();
                }
                else if (a.at(i) == ']') {
                    l.end();
                }
                else {
                    l.append(a.at(i));
                }
            }
        }
    }
}
