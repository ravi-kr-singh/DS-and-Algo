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
  if(head!=NULL){
    show_data(head->link);
    cout<<head->data;
  }
}

node* adding(node* n1,node* n2){
  node* result=NULL;
  int t=0;
  while(n1!=NULL && n2!=NULL){
    t+=(n1->data)+(n2->data);
    insert_data(result,t%10);
    t/=10;
    n1=n1->link;
    n2=n2->link;
  }
  while(n1!=NULL){
    t+=n1->data;
    insert_data(result,t%10);
    t/=10;
    n1=n1->link;
  }
  while(n2!=NULL){
    t+=n2->data;
    insert_data(result,t%10);
    t/=10;
    n2=n2->link;
  }
  if(t!=0)
    insert_data(result,t);
  return result;
}

int main() {
  string num1,num2;
  cout<<"Enter first number : ";
  getline(cin,num1);
  cout<<"Enter second number : ";
  getline(cin,num2);
  node *head1=NULL,*head2=NULL;
  for(int i=num1.size()-1;i>=0;i--){
    insert_data(head1,num1[i]-48);
  }
  for(int i=num2.size()-1;i>=0;i--){
    insert_data(head2,num2[i]-48);
  }

  cout<<"Sum : ";
  show_data(adding(head1,head2));
  return 0;
}
