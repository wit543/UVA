// Example program
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stdlib.h>

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
void LinkedList::print_list()
{
    ListNode* node = header->next;
    while(node != 0) {
        cout << node->val << endl;
        node = node->next;
    }
}
void LinkedList::move(){
    tail=tail->next;
}
valueType LinkedList::pop(){
    tail->next->prev=tail->prev;
    tail->prev->next=tail->next;
    ListNode* temp = tail;
    tail=tail->prev;
    return temp->val;
}
int main(){

   while(true){
       int n=1;
       cin>>n;
       if(n==0){break;}
       int o = 100;
       for(int k=1;k<n;k++) {
           LinkedList* list = new LinkedList();
           for(int i=1;i<=n;i++){
               list->insert(i);
           }
           list->move();
//           cout<<k<<endl;
           for (int i = 0; i < n - 1; i++) {
//               cout<<list->pop()<<" ";
               list->pop();
               for (int j = 0; j < k; j++)
                   list->move();

           }
           if(list->pop()==13){
               o=k;
               break;
           }
//           cout<<endl;
       }
//       cout<<endl;
       cout<<o<<endl;
   }
}
