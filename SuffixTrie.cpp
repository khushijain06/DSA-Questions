#include <iostream>
#include <vector>
#include<string>
using namespace std;


class TrieNode{
    public:
       vector<TrieNode*> children; 
       bool isendofword= false;
       TrieNode():
        children(26,nullptr){}
};

class suffixTrie{
     TrieNode * root;
public:
     suffixTrie(){
         root =  new TrieNode();
     }

     TrieNode* bruteForceSuffixTrie(string T){
         int n= T.size(); //abcde //d
         for(int i=n-1;i>=0;i--){
            TrieNode* node=root;  //a
            int j=i; //a //0
            // for abcde folloing suffi strings will be stored e de cde bcde abcde
              //T[j]-'a' is to get that alphabet ind , eg d-'a'= 3 
            while(j<n && node->children[T[j]-'a']!=nullptr){   //3
                node=node->children[T[j]-'a'];
                j++;  
            }
            for(int k=j;k<n;++k){ //k=1 //b
                TrieNode* newnode= new TrieNode();
                node->children[T[k]-'a']=newnode;   //newnode //e->true  //d->e ->true  //c->d->e->true  //bcde->true  //abcde->true
                if(k==n-1) newnode->isendofword=true;  //
                node=newnode;
            }
         }
        return root;
     }
  //e //de //cde //bcde //abcde
     void printTrie(TrieNode* node,string pre=""){   
        for(int i=0;i<26;i++){
            if(node->children[i]!=nullptr){
                char id='a'+i;   //char id =c
                // print only if nodes's child in end of word
             if(node->children[i]->isendofword){
                cout<<pre<<id<<endl;
               }
                printTrie(node->children[i],pre+id); //abcde
            }      
        }
     }
};
int main(){
    //accepts string in lowercase
       suffixTrie M;
       M.printTrie(M.bruteForceSuffixTrie("abcde"));
}