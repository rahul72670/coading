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
void insertAtLast(node* &head,int val){
    node* n= new node(val);
    if(head==NULL){
        head=n;
        return ;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void intersect(node* &head1,node* &head2,int pos){
    node*temp=head1;
    pos--;
    while(pos--){
        temp=temp->next;
    }
    node*temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp->next;
    }
    temp2->next=temp;
}

int length(node* &head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

int intersection(node* &head1,node* &head2){
    int l1=length(head1);
    int l2=length(head2);
    int d=0;
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL)
            return -1;
        d--;    
    }  
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2)
           return ptr1->data;
        ptr1=ptr1->next;
        ptr2=ptr2->next;   
    }
    return -1;
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
    node* head1=NULL;
    node* head2=NULL;
    insertAtLast(head1,1);
    insertAtLast(head1,2);
    insertAtLast(head1,3);
    insertAtLast(head1,4);
    insertAtLast(head1,5);
    insertAtLast(head1,6);
    insertAtLast(head2,7);
    insertAtLast(head2,8);
    intersect(head1,head2,3);
    printList(head1);
    printList(head2);

    cout<<intersection(head1,head2);

}