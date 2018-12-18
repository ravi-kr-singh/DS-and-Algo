#include <iostream>
#include <stdlib.h>
using namespace std;

struct mStacks_in_single_array {
    int num_of_stacks;
    int capacity;
    int*  top;
    int* array;
};
mStacks_in_single_array* create_Stacks (int Total_Stacks,int cap ) {
    mStacks_in_single_array* My_Stack;
    My_Stack=new mStacks_in_single_array;
    My_Stack->num_of_stacks=Total_Stacks;
    My_Stack->capacity=cap;
    My_Stack->array=new int[(My_Stack->num_of_stacks)*(My_Stack->capacity)];
    My_Stack->top=new int[My_Stack->num_of_stacks];
    for(int i=0;i<My_Stack->num_of_stacks;i++) {
        (My_Stack->top)[i]=-1+(i*My_Stack->capacity);
    }
    return My_Stack;
}
bool isFull (mStacks_in_single_array* Stacks, int StackNo) {
    if(((Stacks->top)[StackNo-1])==((Stacks->capacity)*StackNo)-1)
       return true;
    return false;
}
bool isEmpty (mStacks_in_single_array* Stacks, int StackNo) {
    if(((Stacks->top)[StackNo-1])==-1+((StackNo-1)*Stacks->capacity))
       return true;
    return false;
}

void Push_stack (mStacks_in_single_array* My_Stacks,int StackNo,int item) {
    if(!isFull(My_Stacks,StackNo)) {
        (My_Stacks->top)[StackNo-1]++;
        (My_Stacks->array)[(My_Stacks->top)[StackNo-1]]=item;
    }
    else
        cout<<"OVERFLOW!";
}
int Pop_stack (mStacks_in_single_array* My_Stacks,int StackNo) {
    int deleted_item=-1;
    if(!isEmpty(My_Stacks,StackNo)) {
        deleted_item=(My_Stacks->array)[((My_Stacks->top)[StackNo-1])];
        (My_Stacks->top)[StackNo-1]--;
    }
    else
        cout<<"UNDERFLOW!";
    return deleted_item;
}

void show_stack (mStacks_in_single_array* My_Stacks,int Stack_number) {
    cout<<"\nStack No."<<Stack_number<<" is as follows:-\n";
    for(int i=(((My_Stacks->capacity)*Stack_number)-1); i>=((Stack_number-1)*My_Stacks->capacity);i--) {
        if(((My_Stacks->top)[Stack_number-1])>=i)
            cout<<(i-((My_Stacks->capacity)*(Stack_number-1))+1)<<".   "<<((My_Stacks->array)[i])<<endl;

        else
            cout<<(i-((My_Stacks->capacity)*(Stack_number-1))+1)<<".   "<<"____"<<endl;

    }
}
void show_all_stacks (mStacks_in_single_array* stacks) {
    for(int i=0;i<stacks->num_of_stacks;i++)
        show_stack(stacks,i+1);
}
void Checking_Overflow_for_all (mStacks_in_single_array* stacks) {
    cout<<endl;
    for(int i=0;i<stacks->num_of_stacks;i++) {
        if(isFull(stacks,i+1))
            cout<<"Stack "<<i+1<<" is Overflow.\n";
        else
            cout<<"Stack "<<i+1<<" is not Overflow.\n";
    }
}
void Checking_Underflow_for_all (mStacks_in_single_array* stacks) {
    cout<<endl;
    for(int i=0;i<stacks->num_of_stacks;i++) {
        if(isEmpty(stacks,i+1))
            cout<<"Stack "<<i+1<<" is Underflow.\n";
        else
            cout<<"Stack "<<i+1<<" is not Underflow.\n";
    }
}

int main()
{
    system("cls");
    int Total_num_of_stacks,Stack_size;
    cout<<"How many Stacks you want to implement in an array ? ";
    cin>>Total_num_of_stacks;
    cout<<"Enter size of Stack : ";
    cin>>Stack_size;
    mStacks_in_single_array* STACKS =create_Stacks(Total_num_of_stacks,Stack_size);
    int choice;
    cout<<endl<<"1.Push an element in any of the "<<Total_num_of_stacks<<" stacks.";
    cout<<endl<<"2.Pop an element in any of the "<<Total_num_of_stacks<<" stacks.";
    cout<<endl<<"3.Show any of the "<<Total_num_of_stacks<<" stacks.";
    cout<<endl<<"4.Show all of the "<<Total_num_of_stacks<<" stacks.";
    cout<<endl<<"5.Check Overflow condition for any of the "<<Total_num_of_stacks<<" stacks.";
    cout<<endl<<"6.Check Underflow condition for any of the "<<Total_num_of_stacks<<" stacks.";
    cout<<endl<<"7.Check Overflow condition for all of the "<<Total_num_of_stacks<<" stacks.";
    cout<<endl<<"8.Check Underflow condition for all of the "<<Total_num_of_stacks<<" stacks.\n";
    cout<<"\nEnter your choice: ";
    cin>>choice;
    label:
    int S_no;
    switch(choice) {
        case 1:
            int item;
            cout<<"\nEnter Stack number in which you want to push an element : ";
            cin>>S_no;
            cout<<"Enter element you want to push in Stack "<<S_no<<" : ";
            cin>>item;
            Push_stack(STACKS,S_no,item);
            break;
        case 2:
            cout<<"\nEnter Stack number in which you want to pop an element : ";
            cin>>S_no;
            if(!isEmpty(STACKS,S_no))
                cout<<"\nDeleted item from Stack "<<S_no<<" : "<<Pop_stack(STACKS,S_no)<<".";
            else
                cout<<"\nStack "<<S_no<<" is Underflow.";
            break;
        case 3:
            cout<<"\nEnter Stack number : ";
            cin>>S_no;
            show_stack(STACKS,S_no);
            break;
        case 4:
            show_all_stacks(STACKS);
            break;
        case 5:
            cout<<"\nEnter Stack number for which you want to check Overflow condition : ";
            cin>>S_no;
            if(isFull(STACKS,S_no)) {
                cout<<"Stack "<<S_no<<" is OVERFLOW.";
            }
            else
                cout<<"Stack "<<S_no<<" is not OVERFLOW.";
            break;
        case 6:
            cout<<"\nEnter Stack number for which you want to check Underflow condition : ";
            cin>>S_no;
            if(isFull(STACKS,S_no)) {
                cout<<"Stack "<<S_no<<" is UNDERFLOW.";
            }
            else
                cout<<"Stack "<<S_no<<" is not UNDERFLOW.";
            break;
        case 7:
            Checking_Overflow_for_all(STACKS);
            break;
        case 8:
            Checking_Underflow_for_all(STACKS);
            break;
        default:
            cout<<"Wrong INPUT! Enter your choice number again : ";
            cin>>choice;
            goto label;
            break;
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

    return 0;
}
