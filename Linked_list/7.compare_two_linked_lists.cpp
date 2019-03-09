//Return true if list are same and false otherwise.

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

bool compare_lists(node* h1,node* h2){
  while(h1!=NULL && h2!=NULL){
    if(h1->data!=h2->data)
      return false;
    h1=h1->link;
    h2=h2->link;
  }
  if(h1==NULL && h2==NULL)
    return true;
  else
    return false;
}

bool compare_lists_recursive(node* h1,node* h2){
  if(h1!=NULL && h2!=NULL){
    if(h1->data!=h2->data)
      return false;
    else
      return compare_lists_recursive(h1->link,h2->link);
  }
  else{
    if(h1==NULL && h2==NULL)
      return true;
    return false;
  }
}

int main() {
  node *HEAD1=NULL,*HEAD2=NULL;
  insert_data(HEAD1,44);
  insert_data(HEAD1,15);
  insert_data(HEAD1,23);
  insert_data(HEAD1,9);
  insert_data(HEAD1,41);
  insert_data(HEAD1,18);
  insert_data(HEAD2,44);
  insert_data(HEAD2,15);
  insert_data(HEAD2,23);
  insert_data(HEAD2,19);
  insert_data(HEAD2,41);
  insert_data(HEAD2,18);
  cout<<"Linked list 1 : ";
  show_data(HEAD1);
  cout<<"\nLinked list 2 : ";
  show_data(HEAD2);
  if(compare_lists(HEAD1,HEAD2))
    cout<<"\nList 1 and List 2 are same.";
  else
    cout<<"\nList 1 and List 2 are not same.";
  cout<<"\nComparing lists using recursive approach :-";
  if(compare_lists_recursive(HEAD1,HEAD2))
    cout<<"\nList 1 and List 2 are same.";
  else
    cout<<"\nList 1 and List 2 are not same.";
  return 0;
}
