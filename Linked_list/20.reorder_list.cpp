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
  return n;
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
   if(head==NULL)
    return head;
   int n=(list_size(head)/2)-1;
   if(n<1)
    return head;
   node* temp=head;
   while(n!=0){
     temp=temp->link;
     n--;
   }
   node* second_half=temp->link;
   temp->link=NULL;
   second_half=reverse(second_half);
   temp=head;
   node* ahead_1=temp->link;
   node* ahead_2=second_half->link;
   while(temp!=NULL){
     temp->link=second_half;
     if(ahead_1!=NULL)
      second_half->link=ahead_1;
     temp=ahead_1;
     second_half=ahead_2;
     if(temp!=NULL)
      ahead_1=ahead_1->link;
     if(second_half!=NULL)
      ahead_2=ahead_2->link;
   }
   return head;
 }

 int main() {
   node* HEAD=NULL;
   insert_data(HEAD,1);
   insert_data(HEAD,2);
   insert_data(HEAD,3);
   insert_data(HEAD,4);
   insert_data(HEAD,5);
   insert_data(HEAD,6);
   insert_data(HEAD,7);
   cout<<"Linked list : ";
   show_data(HEAD);
   HEAD=reorder_list(HEAD);
   cout<<"\nAfter reordering, Linked list : ";
   show_data(HEAD);
   return 0;
 }
