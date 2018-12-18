#include <iostream>
#include <iomanip>
#include <stdlib.h>
struct node{
    int data;
    node* next;
    node(int);
};
node* START= nullptr;

node::node(int a){
    data=a;
    next=nullptr;
}
void insert_node(int item){
    node* new_node=new node(item);
    if(START==nullptr){
       START=new_node;
    }
    else{
        if(new_node->data<START->data){
            node* t=START;
            new_node->next=t;
            START=new_node;
        }
        else{
            node* temp=START;
            while(temp->next!=nullptr){
                if((temp->next)->data<new_node->data)
                    temp=temp->next;
                else
                    break;
            }
            new_node->next=temp->next;
            temp->next=new_node;
        }
    }
}

int delete_node(int node_number){
    int item;
    node* temp=START;
    if(node_number==1){
        item=temp->data;
        START=START->next;
        delete temp;
    }
    else {
        int n=node_number;
        while(n-2>0){
                temp=temp->next;
                n--;
            }
        node* t=temp->next;
        item=t->data;
        temp->next=t->next;
        delete t;
    }
    return item;
}
void Show_node(){
    node* t=START;
    std::cout<<"\nSTART->";
    while(t!=NULL){
        std::cout<<t->data<<"->";
        t=t->next;
    }
    std::cout<<"NULL\n";
}
int Size_of_list(){
    int counter=0;
    node* t=START;
    while(t!=NULL){
        counter++;
        t=t->next;
    }
    return counter;
}
bool isValid(int n){
    if(n>0 && n<=Size_of_list())
        return true;
    return false;
}

int main()
{
    system("cls");
    int n;
    std::cout<<std::endl<<std::setw(65)<<"Insert a node: 1\n";
    std::cout<<std::setw(65)<<"Delete any given node: 2\n";
    std::cout<<std::setw(65)<<"Show List : 3\n";
    std::cout<<std::setw(65)<<"Show size of List : 4\n";
    std::cout<<"\nEnter your choice...";
    label1:
    std::cin>>n;
    switch(n){
        case 1:
            int item;
            std::cout<<"Enter element : ";
            std::cin>>item;
            insert_node(item);
            break;
        case 2:
            int node_num;
            std::cout<<"Enter Node number : ";
            label3:
            std::cin>>node_num;
            if(isValid(node_num))
                std::cout<<"Deleting node "<<node_num<<" with value "<<delete_node(node_num)<<".\n";
            else{
                std::cout<<"Node "<<node_num<<" doesn't exist!\n";
                std::cout<<"Enter a valid Node number : ";
                goto label3;
            }
            break;
        case 3:
            Show_node();
            break;
        case 4:
            std::cout<<"Size of Linked List is "<<Size_of_list()<<".\n";
            break;
        default:
            std::cout<<"We does not verify your input\nEnter your choice again: ";
                goto label1;

    }
    std::string decision;
    std::cout<<"\nDo you want to perfom any of the operation again : ";
    label2:
    std::cin>>decision;
    if(decision=="YES" || decision=="yes" || decision=="Yes" ||decision=="y" ||decision=="Y" ) {
        std::cout <<"Enter your choice : ";
        goto label1;
    }
    else if (decision=="NO" || decision=="No" || decision=="no" ||decision=="n" ||decision=="N"  ) {
        std::cout<<"\nOK!";
    }
    else {
        std::cout<<"\nWe cannot identify your input. Enter Yes or No : ";
        goto label2;
    }
    std::cout<<std::endl;
    system("pause");

    return 0;
}
