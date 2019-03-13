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

 node* reorder_list(node* head){
   
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
