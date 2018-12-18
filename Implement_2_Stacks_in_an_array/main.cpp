#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
struct STACK{
    int capacity[2];
    int top[2];
    int* array;
};
STACK* create_Stacks(){
    int arr_size;
    STACK* my_stack=new STACK;
    std::cout<<"Enter Size of array in which you want to implement two Stacks : ";
    std::cin>>arr_size;
    my_stack->array=new int[arr_size];
    my_stack->capacity[0]=arr_size/2;
    my_stack->capacity[1]=arr_size-my_stack->capacity[0];
    my_stack->top[0]=-1;
    my_stack->top[1]=(my_stack->capacity[0])-1;
    return my_stack;
}

bool isFull(STACK* my_stk,int stk_no){
    if(stk_no==1){
        if(my_stk->top[0]==my_stk->capacity[0]-1)
            return true;
        return false;
    }
    else if(stk_no==2){
        if(my_stk->top[1]==my_stk->capacity[0]+my_stk->capacity[1]-1)
            return true;
        return false;
    }
    return false;
}
bool isEmpty(STACK* my_stk,int stk_no){
    if(stk_no==1){
        if(my_stk->top[stk_no-1]==-1)
            return true;
        return false;
    }
    else if(stk_no==2){
        if(my_stk->top[stk_no-1]==my_stk->capacity[0]-1)
            return true;
        return false;
    }
    return false;
}

void insert_data(STACK* my_stack,int data,int stack_no){
    if(!isFull(my_stack,stack_no)){
        (my_stack->top[stack_no-1])++;
        my_stack->array[my_stack->top[stack_no-1]]=data;
    }
}
int delete_data(STACK* my_stack,int data,int stack_no){
    if(!isEmpty(my_stack,stack_no)){
        int deleted_item=my_stack->array[my_stack->top[stack_no-1]];
        (my_stack->top[stack_no-1])--;
        return deleted_item;
    }
    return -1;
}

void show_stack(STACK* Stacks,int stk_no){
    int m;
    if(stk_no==1)
        m=0;
    else
        m=Stacks->capacity[0];
    for(int i=(Stacks->capacity[stk_no-1])-1;i>=0;i--){
        if(i+m<=Stacks->top[stk_no-1]){
            std::cout<<i+1<<". "<<Stacks->array[i+m]<<std::endl;
        }
        else{
            std::cout<<i+1<<"______"<<std::endl;
        }
    }
}

int main()
{
    STACK* Stks=create_Stacks();
    int n;
    std::cout<<std::endl<<std::setw(65)<<"Push an Element in any of the two STACKs : 1\n";
    std::cout<<std::setw(65)<<"Pop an Element in any of the two STACKs : 2\n";
    std::cout<<std::setw(65)<<"Check whether any of the two STACK is underflow or not : 3\n";
    std::cout<<std::setw(65)<<"Check whether STACK is overflow or not : 4\n";
    std::cout<<std::setw(65)<<"Show any of the two STACKs : 5\n";
    std::cout<<"\nEnter your choice...";
    label1:
    std::cin>>n;
    switch(n){
        case 1:
            int stk_no;
            std::cout<<"Enter Stack Number : ";
            std::cin>>stk_no;
            if(isFull(Stks,stk_no))
                std::cout<<"STACK "<<stk_no<<" is OVERFLOW\n";
            else{
                int data;
                std::cout<<"Enter Element : ";
                std::cin>>data;
                insert_data(Stks,data,stk_no);
            }
            break;
        case 2:
            std::cout<<"Enter Stack Number : ";
            std::cin>>stk_no;
            if(isEmpty(Stks,stk_no))
                std::cout<<"STACK "<<stk_no<<" is UNDERFLOW\n";
            else{
                int data=delete_data(Stks,data,stk_no);
                std::cout<<"Top element with value "<<data<<" deleted from STACK "<<stk_no<<"."<<std::endl;
            }
            break;
        case 3:
            std::cout<<"Enter Stack Number : ";
            std::cin>>stk_no;
            if(isEmpty(Stks,stk_no))
                std::cout<<"STACK "<<stk_no<<" is UNDERFLOW\n";
            else{
                std::cout<<"STACK "<<stk_no<<" is not UNDERFLOW\n";
            }
            break;
        case 4:
            std::cout<<"Enter Stack Number : ";
            std::cin>>stk_no;
            if(isFull(Stks,stk_no))
                std::cout<<"STACK "<<stk_no<<" is OVERFLOW\n";
            else{
                std::cout<<"STACK "<<stk_no<<" is not OVERFLOW\n";
            }
            break;
        case 5:
            std::cout<<"Enter Stack Number : ";
            std::cin>>stk_no;
            show_stack(Stks,stk_no);
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
