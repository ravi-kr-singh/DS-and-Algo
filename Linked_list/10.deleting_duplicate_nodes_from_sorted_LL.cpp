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
  node* new_node=new node(item);
    if(head==NULL || head->data>=item){
      new_node->link=head;
      head=new_node;
    }
    else{
      node* temp=head;
      while(temp->link!=NULL && item>temp->link->data)
       temp=temp->link;
     new_node->link=temp->link;
     temp->link=new_node;
    }

}

void show_data(node* head) {
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->link;
  }
}

void deleting_duplicate_nodes(node* head){
  while(head->link!=NULL){
    if(head->data==head->link->data){
      node* temp =head->link;
      head->link=temp->link;
      delete temp;
    }
    else{
      if(head->link!=NULL)
        head=head->link;
    }
  }
}

int main() {
  node* HEAD1=NULL;
  insert_data(HEAD1,44);
  insert_data(HEAD1,15);
  insert_data(HEAD1,23);
  insert_data(HEAD1,23);
  insert_data(HEAD1,23);
  insert_data(HEAD1,15);
  insert_data(HEAD1,15);
  insert_data(HEAD1,56);
  insert_data(HEAD1,56);
  cout<<"Linked list : ";
  show_data(HEAD1);
  cout<<"\nAfter deleting duplicate nodes, Linked list : ";
  deleting_duplicate_nodes(HEAD1);
  show_data(HEAD1);
  return 0;
}
