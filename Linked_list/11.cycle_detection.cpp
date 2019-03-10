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

bool cycle_detection(node* h){
  if(h!=NULL){
    node* slow=h;
    node* fast=h;
    while(fast!=NULL && fast->link!=NULL){
      slow=slow->link;
      fast=fast->link->link;
      if(slow==fast)
        return true;
    }
  }
  return false;
}

int main() {
  node* HEAD=NULL;
  insert_data(HEAD,45);
  insert_data(HEAD,12);
  insert_data(HEAD,51);
  insert_data(HEAD,23);
  node* temp=HEAD;
  while(temp->link!=NULL)
    temp=temp->link;
  temp->link=HEAD->link;
  if(cycle_detection(HEAD))
    cout<<"\nCycle has been detected :(";
  else
    cout<<"\nNo cycle detected :)";
  return 0;
}
