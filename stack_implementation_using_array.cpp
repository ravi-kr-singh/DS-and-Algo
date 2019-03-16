#include <iostream>
#include <stdlib.h>
using namespace std;

struct Stack_using_array {
    int top;
    int capacity;
    int *array;
};

Stack_using_array* Create_Stack(int cap) {
    Stack_using_array* stack;
    stack=new Stack_using_array;
    stack->array=new int[stack->capacity];
    stack->capacity=cap;
    stack->top=-1;
    return stack;
}
bool isFull (Stack_using_array* stack) {
    if(stack->top==(stack->capacity)-1)
        return true;
    return false;
}
bool isEmpty (Stack_using_array* stack) {
    if(stack->top==-1)
        return true;
    return false;
}
void Push (Stack_using_array* stack,int item) {
    if(!isFull(stack)) {
        (stack->top)++;
        (stack->array)[stack->top]=item;
    }
    else {
        cout<<"OVERFLOW\n";
    }
}
int Pop (Stack_using_array* stack) {
    int item=-1;
    if(!isEmpty(stack)) {
        item=stack->array[stack->top];
        (stack->top)--;
    }
    else {
        cout<<"UNDERFLOW\n";
    }
    return item;
}
void Show_Stack (Stack_using_array* stack) {
    cout<<"\nStack :-";
    for(int i=(stack->capacity)-1;i>=0;i--) {
        if(i<=stack->top)
            cout<<endl<<i+1<<".  "<<(stack->array)[i];
        else
            cout<<endl<<i+1<<".  _____";
    }
    cout<<endl;
}
int main(){
    system("cls");
    int size_of_stack,choice;
    cout<<"Enter Size for Stack : ";
    cin>>size_of_stack;
    Stack_using_array* My_stack=Create_Stack(size_of_stack);
    cout<<"                           Push an element in Stack    : 1";
    cout<<"\n                           Pop an element in Stck      : 2";
    cout<<"\n                           Show Stack                  : 3";
    cout<<"\n                           Check if stack is Overflow  : 4";
    cout<<"\n                           Check if stack is Underflow : 5";
    cout<<"\nYour Choice Number : ";
    cin>>choice;
    label:
    switch(choice) {
        case 1:
            int item;
            cout<<"\nEnter the element you want to push : ";
            cin>>item;
            Push(My_stack,item);
            break;
        case 2:
            if(!isEmpty(My_stack))
                cout<<"\nDeleted item from stack : "<<Pop(My_stack);
            else
                cout<<"\nUNDERFLOW";
            break;
        case 3:
            Show_Stack(My_stack);
            break;
        case 4:
            if(isFull(My_stack))
                cout<<"\nStack is Overflow.";
            else
                cout<<"\nStack is not Overflow.";
            break;
        case 5:
            if(isEmpty(My_stack))
                cout<<"\nStack is Underflow.";
            else
                cout<<"\nStack is not Underflow.";
            break;
        default:
            cout<<"\nWe cannot identify your choice.\nEnter your choice again : ";
            cin>>choice;
            goto label;
    }
    string decision;
    cout<<"\nDo you want to perfom any of the operation again : ";
    label2:
    cin>>decision;
    if(decision=="YES" || decision=="yes" || decision=="Yes" ||decision=="y" ||decision=="Y" ) {
        cout <<"Enter your choice : ";
        cin>>choice;
        goto label;
    }
    else if (decision=="NO" || decision=="No" || decision=="no" ||decision=="n" ||decision=="N"  ) {
        cout<<"\nOK!";
    }
    else {
        cout<<"\nWe cannot identify your input. Enter Yes or No : ";
        goto label2;
    }
    cout<<endl;
    system("pause");
    return 1;
}
