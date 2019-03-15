/*Given a linked list, swap every two adjacent nodes and return its
head. You may not modify the values in the list's nodes, only nodes
itself may be changed.
Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.*/

#include <iostream>
using namespace std;

struct node {
  int data;
  node* link;
  node(int item){
    data=item;
    link=NULL;
  }
};
void insert_data(node* &head, int item) {
  if(head==NULL)
    head=new node(item);
  else{
    node* temp=head;
    while(temp->link!=NULL)
      temp=temp->link;
    temp->link=new node(item);
  }
}

void show_data(node* head) {
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->link;
  }
}

node* swap_nodes_in_pairs(node* head){
  if(head==NULL || head->link==NULL)
    return head;
  node *temp=head,*prev=NULL;
  head=head->link;
  while(temp!=NULL && temp->link!=NULL){
    node* t=temp->link;
    if(prev!=NULL)
      prev->link=t;
    temp->link=t->link;
    t->link=temp;
    prev=temp;
    temp=temp->link;
  }
  return head;
}

int main() {
  node* HEAD=NULL;
  insert_data(HEAD,1);
  insert_data(HEAD,2);
  insert_data(HEAD,3);
  insert_data(HEAD,4);
  insert_data(HEAD,5);
  insert_data(HEAD,6);
  cout<<"Linked list : ";
  show_data(HEAD);
  cout<<"\nAfter swapping in pairs , Linked list : ";
  HEAD=swap_nodes_in_pairs(HEAD);
  show_data(HEAD);
  return 0;
}
