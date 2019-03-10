/* The data in both lists are sorted in ascending order.Merge both
   the lists so that the resultant list is sorted in ascending order. */

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

   node* merge_lists(node* h1,node* h2){
     node* new_list=NULL;
     node* t=new_list;
     while(h1!=NULL && h2!=NULL){
       if(h1->data<=h2->data){
         node* new_node=new node(h1->data);
         if(t==NULL){
           new_list=new_node;
           t=new_list;
         }
         else{
           t->link=new_node;
           t=t->link;
         }
         h1=h1->link;
       }
       else{
         node* new_node=new node(h2->data);
         if(t==NULL){
           new_list=new_node;
           t=new_list;
         }
         else{
           t->link=new_node;
           t=t->link;
         }
         h2=h2->link;
       }
     }
     if(h1==NULL && h2!=NULL)
       t->link=h2;
     else
      t->link=h1;
    return new_list;
   }

   int main() {
     node* HEAD1=NULL;
     insert_data(HEAD1,44);
     insert_data(HEAD1,15);
     insert_data(HEAD1,23);
     insert_data(HEAD1,9);
     insert_data(HEAD1,87);
     insert_data(HEAD1,136);
     insert_data(HEAD1,43);
     insert_data(HEAD1,18);
     cout<<"Linked list 1: ";
     show_data(HEAD1);
     node* HEAD2=NULL;
     insert_data(HEAD2,32);
     insert_data(HEAD2,61);
     insert_data(HEAD2,23);
     insert_data(HEAD2,10);
     insert_data(HEAD2,101);
     insert_data(HEAD2,55);
     cout<<"\nLinked list 2: ";
     show_data(HEAD2);
     cout<<"\nFinal merged list : ";
     show_data(merge_lists(HEAD1,HEAD2));
     return 0;
   }
