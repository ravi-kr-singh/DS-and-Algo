/* You’re given the pointer to the head node of a linked list and a
specific position. Counting backwards from the tail node of the linked
list, get the value of the node at the given position. A position of 0
corresponds to the tail, 1 corresponds to the node before the tail
and so on.*/

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

int size_calculator(node* head){
  int size=0;
  while(head!=NULL){
    size++;
    head=head->link;
  }
  return size;
}

bool check_pos(node* head,int pos){
  int size=size_calculator(head);
  size--;
  if(size>=pos && pos>=0)
    return true;
  return false;
}

int get_node_value(node* h,int pos){
  int n=size_calculator(h)-pos-1;
  while(n!=0){
    h=h->link;
    n--;
  }
  return h->data;
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
  int i;
  label:
  cout<<"\nEnter Position :";
  cin>>i;
  if(check_pos(HEAD,i))
    cout<<"Node value at position "<<i<<" : "<<get_node_value(HEAD,i);
  else{
    cout<<"Invalid position !";
    goto label;
  }
  return 0;
}
