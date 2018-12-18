#include <iostream>
#include <stdio.h>

struct node {
    int info;
    node *prev,*next;
};
node* START=NULL;

void Insert_at_beginning(int Data) {
    node* new_node=new node;
    new_node->info=Data;
    new_node->prev=NULL;
    new_node->next=NULL;
    if(START==NULL)
        START=new_node;
    else{
        START->prev=new_node;
        new_node->next=START;
        START=new_node;
    }
}

void delete_first_node() {
    if(START==NULL)
        std::cout<<"List is Empty!";
    else {
        node* temp=START;
        START=START->next;
        START->prev=NULL;
        delete temp;
    }
}

void View_List() {
    if(START==NULL)
        std::cout<<"List is Empty.";
    else {
        node* Temp=START;
        while(Temp=NULL){
            std::cout<<Temp->info<<" ";
            Temp=Temp->next;
        }
    }
}


int main()
{
    Insert_at_beginning(56);
    Insert_at_beginning(55);
    Insert_at_beginning(106);
    Insert_at_beginning(156);
    View_List();
    return 0;
}
