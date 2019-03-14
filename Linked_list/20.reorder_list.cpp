/*Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You may not modify the values in the list's nodes, only nodes itself
 may be changed.*/


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

int list_size(node* head){
  int n=0;
  while(head!=NULL){
    n++;
    head=head->link;
  }
  return head;
}

node* reverse(node* h){
  node *curr=h,*prev=NULL;
  node* next_node;
  if(h!=NULL)
    next_node=h->link;
  while(curr!=NULL){
    curr->link=prev;
    prev=curr;
    curr=next_node;
    if(curr!=NULL)
      next_node=next_node->link;
  }
  h=prev;
  return h;
}

 node* reorder_list(node* head){
   int n=list_size(head);
   if(n%2==0){
     n=(n/2)-1;
   else
    n=n/2;
   node* temp=head;
   while(n!=0){
     temp=temp->link;
   }
   node* second_half=temp->link;
   temp->link=NULL;
   second_half=reverse(second_half);
   temp=head;
   node* ahead=NULL;
   if(head!=NULL)
    ahead=temp->link;
   while(second_half!=NULL){
     temp->link=second_half;
     temp=ahead;
     if(ahead!=NULL)
      ahead=ahead->link;
     second_half=second_half->link;
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
   HEAD=reorder_list(HEAD);
   cout<<"\nAfter reordering, Linked list : ";
   show_data(HEAD);
   return 0;
 }
