/*Given a singly linked list, group all odd nodes together followed
 by the even nodes. Please note here we are talking about the node
 number and not the value in the nodes.*/

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

 void odd_even_list(node*& HEAD){
   node* odd=HEAD;
   node *even=NULL;
   if(HEAD!=NULL){
     even=HEAD->link;
   }
   node* temp=even;
   while(even!=NULL){
    if(odd->link!=NULL)
      odd->link=odd->link->link;
    if(even->link!=NULL)
      even->link=even->link->link;
    even=even->link;
    if(odd->link!=NULL)
      odd=odd->link;
   }
   if(odd!=NULL)
    odd->link=temp;

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
   insert_data(HEAD,8);
   insert_data(HEAD,9);
   insert_data(HEAD,10);
   insert_data(HEAD,11);
   insert_data(HEAD,12);
   cout<<"Linked list : ";
   show_data(HEAD);

   odd_even_list(HEAD);
   cout<<"\nPairing odd nodes together and even nodes together ,resultant Linked list : ";
   show_data(HEAD);
   return 0;
 }
