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
bool check_pos(node* head,int pos){
  int size=0;
  while(head!=NULL){
    size++;
    head=head->link;
  }
  if(size>=pos && pos>=1)
    return true;
  return false;
}

void delete_node(node* &head,int position){
  if(position==1){
    node* temp=head;
    head=head->link;
    delete temp;
  }
  else{
    node* temp=head;
    while(position!=2){
      temp=temp->link;
      position--;
    }
    node* d_node=temp->link;
    temp->link=d_node->link;
    delete d_node;
  }
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
  int position;
  label:
  cout<<"\nEnter Positon for Deletion : ";
  cin>>position;
  if(check_pos(HEAD,position))
    delete_node(HEAD,position);
  else{
    cout<<"Invalid Position!";
    goto label;
  }
  cout<<"\nAfter deletion , Linked List : ";
  show_data(HEAD);
  return 0;
}
