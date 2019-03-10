#include <iostream>
#include <vector>
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

void merge_pt(node* h1,node* h2){
  node* t=h2;
  while(h1!=NULL){
    while(t!=NULL){
      if(t==h1){
        cout<<"\nMerge node : "<<h1->data;
        return;
      }
      t=t->link;
    }
    h1=h1->link;
    t=h2;
  }
  cout<<"\nNo merge point found.";
}

int main() {
  node *HEAD1=NULL,*HEAD2=NULL;
  insert_data(HEAD1,45);
  insert_data(HEAD1,12);
  insert_data(HEAD1,25);
  insert_data(HEAD1,33);
  insert_data(HEAD1,52);
  insert_data(HEAD1,29);

  insert_data(HEAD2,51);
  insert_data(HEAD2,23);
  insert_data(HEAD2,40);
  insert_data(HEAD2,9);
  node* temp=HEAD2;
  while(temp->link!=NULL)
    temp=temp->link;
  temp->link=HEAD1->link->link->link; //Creating merge pt at Node 33.

  cout<<"Linked list 1 : ";
  show_data(HEAD1);
  cout<<"\nLinked list 2 : ";
  show_data(HEAD2);
  merge_pt(HEAD1,HEAD2);

  return 0;
}
