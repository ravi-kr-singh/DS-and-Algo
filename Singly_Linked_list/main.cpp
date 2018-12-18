#include <iostream>
#include <stdio.h>
struct node {
    int info;
    node* link;
};
node* START=NULL;
void insert_at_end(int num) {
    node* my_node=new node;
    my_node->info=num;
    my_node->link=NULL;
    if(START==NULL)
        START=my_node;
    else {
        node* Temp=START;
        while(Temp->link!=NULL)
            Temp=Temp->link;
        Temp->link=my_node;
    }
}
void insert_at_beginning(int data) {
    node* my_node=new node;
    my_node->info=data;
    if(START!=NULL) {
        my_node->link=START->link;
        START=my_node;
    }
    else{
        my_node->link=NULL;
        START=my_node;
    }
}

int length_of_list() {
    node* temp=START;
    int counter=0;
    while(temp!=NULL){
        temp=temp->link;
        counter++;
    }
    return counter;
}

bool check(int pos_no){
    int len=length_of_list();
    if(pos_no>0 && pos_no<=(len+1))
        return true;
    else
        return false;
}
void insert_at_particular_position(int pos,int data) {
    node* my_node=new node;
    my_node->info=data;
    node* temp=START;
    if(check(pos)==true) {
        while((pos-2)!=0){
            temp=temp->link;
            pos--;
        }
        my_node->link=temp->link;
        temp->link=my_node;
    }
    else
        std::cout<<"Invalid operation!\n";
}



void Delete_first_node() {
    if(START==NULL)
        std::cout<<"Invalid Operation! List is already empty";
    else {
        node* r=START;
        START=START->link;
        delete r;
    }

}
void Traverse() {
    if(START==NULL)
        std::cout<<"List is Empty.";
    else {
        node* ptr=START;
        int i=1;
        while(ptr!=NULL){
            std::cout<<"Node "<<i<<" : "<<ptr->info<<std::endl;
            ptr=ptr->link;
            i++;
        }
    }
}
void remove_duplicates() {                                 //Assuming List to be sorted
    node* ptr1=START;
    while(ptr1->link!=NULL){
      if(ptr1->info==(ptr1->link)->info) {
        node* t=(ptr1->link);
        ptr1->link=t->link;
        delete t;
      }
      else{
        ptr1=ptr1->link;
      }
    }
}
void Sort_list() {
    node* max=START;
    for(node* ptr=START->link;ptr!=NULL;ptr=ptr->link){
        if(max->info<ptr->info)
            max=ptr;
    }

}


int main() {
    int a;
    std::cout<<"How many elements you want to enter ? ";
    std::cin>>a;
    int elements[a];
    for(int i=0;i<a;i++){
        std::cin>>elements[i];
        insert_at_end(elements[i]);
    }
    std::cout<<"Position number : ";
    std::cin>>a;
    insert_at_particular_position(a,102);
    Traverse();
    remove_duplicates();
    std::cout<<std::endl;
    Traverse();
    std::cout<<std::endl<<length_of_list();
    return 0;
}
