#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Node {
public:
    int val;
    Node* next;

    Node() {
        val = 0;
        next = nullptr;
    }

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};
class ll{
    public:
           Node *head;
       ll(){
          head=nullptr;
       }
       vector<int> nodesBetweenCriticalPoints(Node* head){
          vector<int> indexes;
          Node* prev=head;
          Node*curr=prev->next;
    Node* Next=curr->next;
   // if(Next==nullptr) return{-1,-1};
    int indx=2;
    while (Next!=nullptr){
        int curv=curr->val;
        int prevv=prev->val;
        int Nextv=Next->val;
        if((curv<prevv && curv<Nextv) ||(curv>prevv && curv>Nextv)){
            indexes.push_back(indx);
        }
        prev=curr;
        curr=Next;
        Next=Next->next;
        indx++;
    }
      int n=indexes.size();
      if(n<2) {return {-1,-1};}
      int maxd=indexes[n-1]-indexes[0];
      int mind=INT_MAX;
      for(int i=1;i<n;i++){
        mind=min(mind,indexes[i]-indexes[i-1]);
      }
      return {mind,maxd};
   }
};
int main(){
    ll obj;
    //5->3->1->2->5->1->2
    Node * head1=new Node(5);
    Node* se=new Node(3);
    Node* th=new Node(1);
    Node* fo=new Node(2);
    Node* fi=new Node(5);
    Node *si=new Node(1);
    Node *sev=new Node(2);
    head1->next=se;
    se->next=th;
    th->next=fo;
    fo->next=fi;
    fi->next=si;
    si->next=sev;
    vector<int> ans;
    ans=obj.nodesBetweenCriticalPoints(head1);
    cout<<"jo";
   cout<<ans[0]<<ans[1]<<" ";
    return 0;
}