#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
      int data;
      node* next;
      node* prev;
      node(int val){
          data =val;
          next=NULL;
          prev=NULL;
      }
};

void insertAthead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    if(head!=NULL){
      head->prev=n;
    }
    head=n;  
}

void insertAtLast(node* &head,int val){
    node* n= new node(val);
    if(head==NULL){
        insertAthead(head,val);
        return ;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}



void printList(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    printList(head);
    insertAthead(head,1);
       printList(head);
    insertAtLast(head,2);
    insertAtLast(head,3);
    insertAtLast(head,4);
    printList(head);
}