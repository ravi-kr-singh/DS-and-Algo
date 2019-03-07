#include <iostream>
#include <stdio.h>
#include <math.h>
struct node{
    int info;
    node* link;
};
node* START[3]={NULL,NULL,NULL};

void input(int LL_num,int Data){
    node* Temp=new node;
    Temp->link=NULL;
    Temp->info=Data;
    if(START[LL_num-1]==NULL)
        START[LL_num-1]=Temp;
    else {
        node* T=START[LL_num-1];
        while(T->link!=NULL)
            T=T->link;
        T->link=Temp;
    }
}


std::string Addition(int LL_num1,int LL_num2){
    std::string temp;
    node* T1=START[LL_num1-1];
    node* T2=START[LL_num2-1];
    int t=0;
    while(T1!=NULL && T2!=NULL){
        t+=(T1->info)+(T2->info);
        temp.push_back((t%10)+48);
        t/=10;
        T1=T1->link;
        T2=T2->link;
    }
    if(T1==NULL){
        while(T2!=NULL) {
            t+=T2->info;
            temp.push_back((t%10)+48);
            t/=10;
            T2=T2->link;
        }
    }
    else{
        while(T1!=NULL) {
            t+=T1->info;
            temp.push_back((t%10)+48);
            t/=10;
            T1=T1->link;
        }
    }
    if(t!=0)
        temp.push_back((t%10)+48);
    return temp;
}

int main()
{
    std::string num1,num2,rev_ans;
    std::cout<<"Enter 1st number : ";
    std::getline(std::cin,num1);
    std::cout<<"Enter 2nd number : ";
    std::getline(std::cin,num2);
    for(int i=num1.size()-1;i>=0;i--)
        input(1,num1[i]-48);
    for(int j=num2.size()-1;j>=0;j--)
        input(2,num2[j]-48);
    rev_ans=Addition(1,2);
    std::cout<<"Sum : ";
    for(int i=rev_ans.size()-1;i>=0;i--)
        std::cout<<rev_ans[i];
    return 0;
}
