#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
      int data;
      node* next;
      node(int val){
          data =val;
          next=NULL;
      }
};
void insertAthead(node* &head,int val){
    node* n=new node(val);
    node* temp=head;
    if(head==NULL){
        n->next=n;
        head=n;
        return;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
}

void insertAtLast(node* &head,int val){
    node* n= new node(val);
    if(head==NULL){
        insertAthead(head,val);
        return ;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
}

void deleteAthead(node* &head){
     node* temp=head;
     node* todelete;
     while(temp->next!=head){
         temp=temp->next;
     }
     todelete=head;
     temp->next=head->next;
     head=head->next;
     delete todelete;
}

void deletion(node* & head,int pos){
    if(pos==1){
        deleteAthead(head);
        return ;
    }
    node* temp=head;
    node* todelete;
    int count=1;
    while(count!=pos-1){
       count++;
       temp=temp->next;
    }
    todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

void printList(node* &head){
    node* temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }while(temp!=head);
    cout<<"NULL"<<endl;
}
int main(){
    node* head=NULL;
    insertAtLast(head,1);
    insertAtLast(head,2);
    insertAtLast(head,3);
    insertAtLast(head,4);
      printList(head);
    insertAthead(head,6);
    printList(head);

    deletion(head,4);
    printList(head);
      deletion(head,1);
    printList(head);
}