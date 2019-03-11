/*Given a non-empty, singly linked list with head node head,
return a middle node of linked list.If there are two middle
nodes, return the second middle node.*/

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

int calculate_size(node* h){
  int n=0;
  while(h!=NULL){
    n++;
    h=h->link;
  }
  return n;
}

node* middle_node(node* H){
  int n=calculate_size(H)/2;
  while(n!=0){
    H=H->link;
    n--;
  }
  return H;
}


int main() {
  node* HEAD1=NULL;
  insert_data(HEAD1,44);
  insert_data(HEAD1,15);
  insert_data(HEAD1,23);
  insert_data(HEAD1,19);
  insert_data(HEAD1,43);
  cout<<"Linked list 1: ";
  show_data(HEAD1);

  node* HEAD2=NULL;
  insert_data(HEAD2,29);
  insert_data(HEAD2,73);
  insert_data(HEAD2,61);
  insert_data(HEAD2,80);
  insert_data(HEAD2,18);
  insert_data(HEAD2,36);
  cout<<"\nLinked list 2: ";
  show_data(HEAD2);
  cout<<"\nMiddle Node of List 1 : "<<middle_node(HEAD1)->data;
  cout<<"\nMiddle Node of List 2 : "<<middle_node(HEAD2)->data;
  return 0;
}
