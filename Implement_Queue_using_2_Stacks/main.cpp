#include <iostream>
#include <stdlib.h>
#include <stack>
#include <iomanip>
struct Queue{
    std::stack<int> S1,S2;
    void enQueue(int);
    int deQueue();
    void showQ();
};
void Queue::enQueue(int data){
    S1.push(data);
}
int Queue::deQueue(){
    int x=-1;
    if(S1.empty() && S2.empty()){
        std::cout<<"Queue is Empty.\n";
        return x;
    }
    else{

        while(!S1.empty()){
            S2.push(S1.top());
            S1.pop();
        }
        x=S2.top();
        std::cout<<"Dequeueing...."<<x<<std::endl;
        S2.pop();
        return x;
    }
}

void Queue::showQ(){
    std::stack<int> Stk1=S1,Stk2=S2;
    if(Stk1.empty() && Stk2.empty())
        std::cout<<"Queue is empty";
    else{
        int i=1;
        std::stack<int> Stk3;
        while(!Stk1.empty()){
            Stk3.push(Stk1.top());
            Stk1.pop();
        }
        while(!Stk2.empty()){
            Stk3.push(Stk2.top());
            Stk2.pop();
        }
        while(!Stk3.empty()){
            std::cout<<i<<"."<<Stk3.top()<<"   ";
            Stk3.pop();
            i++;
        }

    }
    std::cout<<'\n';
}

int main(){
    system("cls");
    Queue Q;
    int n;
    std::cout<<std::endl<<std::setw(65)<<"Insert an element in Queue : 1\n";
    std::cout<<std::setw(65)<<"Dequeue an element in Queue : 2\n";
    std::cout<<std::setw(65)<<"Show Queue : 3\n";
    std::cout<<"\nEnter your choice...";
    label1:
    std::cin>>n;
    switch(n){
        case 1:
            int item;
            std::cout<<"Enter element : ";
            std::cin>>item;
            Q.enQueue(item);
            break;
        case 2:
            Q.deQueue();
            break;
        case 3:
            Q.showQ();
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
