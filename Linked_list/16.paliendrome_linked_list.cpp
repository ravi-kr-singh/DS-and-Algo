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

node* reverse_list_copy(node* HEAD){
  node* rev_head=NULL;
  if(HEAD!=NULL){
    node *curr=HEAD,*prev=NULL,*temp=NULL;
    while(curr!=NULL){
      temp=new node(curr->data);
      temp->link=prev;
      prev=temp;
      curr=curr->link;
    }
    rev_head=prev;
  }
  return rev_head;
}

bool isPaliendrome(node* H){
  node* rev_head=reverse_list_copy(H);
  while(H!=NULL){
    if(H->data!=rev_head->data)
      return false;
    rev_head=rev_head->link;
    H=H->link;
  }
  return true;
}

int main() {
  node* HEAD=NULL;
  insert_data(HEAD,44);
  insert_data(HEAD,15);
  insert_data(HEAD,23);
  insert_data(HEAD,23);
  insert_data(HEAD,15);
  insert_data(HEAD,44);
  cout<<"Linked list 1 : ";
  show_data(HEAD);

  node* HEAD2=NULL;
  insert_data(HEAD2,85);
  insert_data(HEAD2,15);
  insert_data(HEAD2,23);
  insert_data(HEAD2,23);
  insert_data(HEAD2,19);
  insert_data(HEAD2,85);
  cout<<"\nLinked list 2 : ";
  show_data(HEAD2);

  if(isPaliendrome(HEAD))
    cout<<"\nList 1 is paliendrome.";
  else
    cout<<"\nList 1 is not paliendrome.";

  if(isPaliendrome(HEAD2))
    cout<<"\nList 2 is paliendrome.";
  else
    cout<<"\nList 2 is not paliendrome.";
  return 0;
}
