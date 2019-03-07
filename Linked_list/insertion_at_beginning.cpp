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
    node* new_node=new node(item);
    new_node->link=head;
    head=new_node;
  }
}

void show_data(node* head) {
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->link;
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
  return 0;
}
