#include <iostream>
#include <iomanip>
#include <stdlib.h>
struct priority_q{
    int data;
    int priority;
    priority_q* next;
    priority_q(int,int);
};
priority_q* START= nullptr;

priority_q::priority_q(int a,int p){
    data=a;
    priority=p;
    next=nullptr;
}
void insert_node(int item,int p){
    priority_q* new_node=new priority_q(item,p);
    if(START==nullptr){
       START=new_node;
    }
    else{
        if(new_node->priority<START->priority){
            priority_q* t=START;
            new_node->next=t;
            START=new_node;
        }
        else{
            priority_q* temp=START;
            while(temp->next!=nullptr){
                if((temp->next)->priority<new_node->priority)
                    temp=temp->next;
                else
                    break;
            }
            new_node->next=temp->next;
            temp->next=new_node;
        }
    }
}

int delete_node(){
    int item=-1;
    if(START!=nullptr){
        priority_q* temp=START;
        item=temp->data;
        START=START->next;
        delete temp;
    }
    return item;
}
void Show_node(){
    priority_q* t=START;
    std::cout<<"Data(priority):  ";
    while(t!=NULL){
        std::cout<<t->data<<"("<<t->priority<<")   ";
        t=t->next;
    }
    std::cout<<"\n";
}
int Size_of_list(){
    int counter=0;
    priority_q* t=START;
    while(t!=NULL){
        counter++;
        t=t->next;
    }
    return counter;
}
int main()
{
    system("cls");
    int n;
    std::cout<<std::endl<<std::setw(65)<<"Enqueue: 1\n";
    std::cout<<std::setw(65)<<"Dequeue: 2\n";
    std::cout<<std::setw(65)<<"Show Priority Queue: 3\n";
    std::cout<<std::setw(65)<<"Show size of Priority Queue : 4\n";
    std::cout<<"\nEnter your choice...";
    label1:
    std::cin>>n;
    switch(n){
        case 1:
            int item,p;
            std::cout<<"Enter element : ";
            std::cin>>item;
            std::cout<<"Enter Priority : ";
            std::cin>>p;
            insert_node(item,p);
            break;
        case 2:
            if(START==nullptr)
                std::cout<<"UNDERFLOW!\n";
            else
                std::cout<<"Deleting..."<<delete_node()<<"\n";
            break;
        case 3:
            if(START==nullptr)
                std::cout<<"Priority Queue is Empty\n";
            else
                Show_node();
            break;
            break;
        case 4:
            std::cout<<"Size of Priority Queue is "<<Size_of_list()<<".\n";
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
