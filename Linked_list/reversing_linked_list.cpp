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

node* reverse_list(node* head){
  node *prev=NULL,*curr=head,*next=head->link;
  while (curr!=NULL) {
    curr->link=prev;
    prev=curr;
    curr=next;
    if(next!=NULL)
      next=next->link;
  }
  head=prev;
  return head;
}

int main() {
  node* HEAD=NULL;
  insert_data(HEAD,44);
  insert_data(HEAD,15);
  insert_data(HEAD,23);
  insert_data(HEAD,19);
  insert_data(HEAD,43);
  insert_data(HEAD,18);
  cout<<"Linked list : ";
  show_data(HEAD);
  HEAD=reverse_list(HEAD);
  cout<<"\nAfter reversing, Linked list : ";
  show_data(HEAD);
  return 0;
}
