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

bool check_pos(int pos,node* head){
  int size=0;
  while(head!=NULL){
    size++;
    head=head->link;
  }
  if(size+1>=pos && pos>=1)
    return true;
  return false;
}

void insert_data(node* &head, int item,int position) {
  if(check_pos(position,head)){
    node* new_node=new node(item);
    if(position==1){
      new_node->link=head;
      head=new_node;
    }
    else{
      node* temp=head;
      while(position!=2) {
        temp=temp->link;
        position--;
      }
      new_node->link=temp->link;
      temp->link=new_node;
    }
  }
  else{
    cout<<"Invalid Position !";
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
  insert_data(HEAD,44,1);
  insert_data(HEAD,15,2);
  insert_data(HEAD,23,1);
  insert_data(HEAD,19,4);
  insert_data(HEAD,43,3);
  insert_data(HEAD,18,1);
  cout<<"Linked list : ";
  show_data(HEAD);
  return 0;
}
