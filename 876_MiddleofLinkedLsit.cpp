#include<iostream>
using namespace std;
class Node{
   public:
      Node* next;
      int data;
      Node(){
        next=nullptr;
        data=0;
      }
      Node(int val){
        this->data=val;
        this->next=nullptr;
      }
};
class ListNode{
    public:
    Node* head;
    ListNode(){
        head=nullptr;
    }
     void insertNode(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    Node * middleNode(Node* head){
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
int main(){
    ListNode ll;
    ll.insertNode(1);
    ll.insertNode(2);
    ll.insertNode(3);
    ll.insertNode(4);
    ll.insertNode(5);
    cout<<"head is: "<< ll.head->data<<"\n";
    Node* ans= ll.middleNode(ll.head);
    while(ans!=nullptr){
        cout<<ans->data<<"->";
        ans=ans->next;
    }
    cout<<"null";
    return 0;
}
