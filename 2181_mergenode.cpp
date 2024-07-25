#include <iostream>
using namespace std;
//node class to contruct node
class Node{
    public:
    int val;
    Node * next;
    //constructor
    Node(){
        val=0;
        next=NULL;
    }
    //initializing node with value
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
//linkedlist class taking node class and initizilaizing head ptr
class LinkedList{
    Node* head;
   public:
   //constructor
   LinkedList(){
    head=NULL;
   }
   //printing list
   void print(Node  *head){
    Node* temp=head;
    while(temp->next!=nullptr){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
   }
};
//solution class for the question
class Solution{
    public:
    Node * merge(Node*head){
        //modify pointer at second node as 1st is 0
    Node* modify=head->next;
       //second node pointer at second node as it is non-zero
    Node* netsum=modify;
    //iterating till end of linked list
    while(netsum!=NULL){
        //sum setting to zero after every modificatiom
        int sum=0;
        //adding sum until 0 value
        while(netsum->val!=0){
            sum+=netsum->val;
            netsum=netsum->next;
        }
        //modifying values
        netsum=netsum->next;
        modify->val=sum;
        modify->next=netsum;
        modify=modify->next;
    }
  return head->next;
    }
};
void print(Node * head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
int main(){
    //making list
    //0->3->1->0->4->5->2->0
    Node* newnode=new Node(0);
    Node* temp1=new Node(3);
    newnode->next=temp1;
    Node * temp2=new  Node(1);
    temp1->next=temp2;
    Node* temp3=new Node(0);
    temp2->next=temp3;
    Node * temp4=new  Node(4);
    temp3->next=temp4;
    Node* temp5=new Node(5);
    temp4->next=temp5;
    Node* temp6=new Node(2);
    temp5->next=temp6;
    Node * temp7=new Node(0);
    temp6->next=temp7;

    cout<<"List before merging"<<" ";
    print(newnode);

   Solution obj;
    Node *ans;
    ans=obj.merge(newnode);
    
       //printing list
       cout<<"after merging"<<" ";
       print(ans);


}