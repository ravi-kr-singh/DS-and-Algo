#include <iostream>
using namespace std;

struct node {             //Doubly linked list
  int data;
  node* next;
  node* prev;
  node(int item){
    data=item;
    next=NULL;
    prev=NULL;
  }
};
void insert_data(node* &head, int item) {
  node* new_node= new node(item);
  if(head==NULL){
    head=new_node;
  }
  else{
    if(item<=head->data){
      new_node->next=head;
      head->prev=new_node;
      head=new_node;
    }
    else{
      node* temp=head;
      while(temp->next!=NULL && item>temp->next->data)
        temp=temp->next;
      new_node->next=temp->next;
      if(temp->next!=NULL)
        temp->next->prev=new_node;
      new_node->prev=temp;
      temp->next=new_node;
    }
  }
}

void show_data(node* head) {
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
}

void rev_list(node* &HEAD){
  node *curr_node=HEAD,*prev_node=NULL,*next_node=HEAD->next;
  while(curr_node!=NULL){
    curr_node->next=prev_node;
    curr_node->prev=next_node;
    prev_node=curr_node;
    curr_node=next_node;
    if(next_node!=NULL)
      next_node=next_node->next;
  }
  HEAD=prev_node;
}

int main() {
  node* HEAD=NULL;
  insert_data(HEAD,44);
  insert_data(HEAD,15);
  insert_data(HEAD,23);
  insert_data(HEAD,9);
  insert_data(HEAD,87);
  insert_data(HEAD,19);
  insert_data(HEAD,43);
  insert_data(HEAD,18);
  cout<<"Linked list : ";
  show_data(HEAD);
  cout<<"\nReversed Linked list : ";
  rev_list(HEAD);
  show_data(HEAD);
  return 0;
}
