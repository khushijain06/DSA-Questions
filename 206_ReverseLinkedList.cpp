#include<iostream>
using namespace std;
class node{
    public:
     node* next;
     int data;
    node(){
        next=nullptr;
        data=0;
    }
    node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
class singly{
    public:
    node* head;
      singly(){
        head=nullptr;
      }
      void insertnode(int data){
        node* newnode=new node(data);
        if(head==nullptr) head=newnode;
        else{
            node* temp=head;
            while(temp->next!=nullptr){
                temp=temp->next;
            }
            temp->next=newnode;
        }
      }
      node* reverseList(node* head){
        node* prev=nullptr;
        node* Next=nullptr;
        node* curr=head;
        while(curr!=nullptr){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
      }
};
int main(){
    singly ll;
    ll.insertnode(1);
    ll.insertnode(2);
    ll.insertnode(3);
    ll.insertnode(4);
    ll.insertnode(5);
    node* ans=ll.reverseList(ll.head);
    while(ans!=nullptr){
        cout<<ans->data<<"->";
        ans=ans->next;
    }
    cout<<"null";
    return 0;
}