#include <iostream>
#include <string>

struct STACK {
    int capacity;
    int top;
    char* array;
};

STACK* create_STACK(int size_of_stack){
    STACK* my_STACK=new STACK;
    my_STACK->capacity=size_of_stack;
    my_STACK->top=-1;
    my_STACK->array=new char[my_STACK->capacity];
}
void Push_Element(char element,STACK* given){
    if(given->top==(given->capacity)-1)
        std::cout<<"Overflow!";
    else {
        (given->top)++;
        (given->array)[given->top]=element;
    }
}
char Pop_Element(STACK* given){
    char to_be_deleted='0';
    if(given->top==-1)
        std::cout<<"Underflow!";
    else{
        to_be_deleted=given->array[given->top];
        (given->top)--;
    }
    return to_be_deleted;
}
void show_stack(STACK* given){
    if(given->top!=(-1))
        for(int i=given->top;i>=0;i--)
            std::cout<<i+1<<". "<<given->array[i]<<std::endl;
    else
        std::cout<<"STACK is Empty!";
}
std::string Infix_to_Postfix(STACK* empty_STACK,std::string Infix){
    std::string Postfix;
    Push_Element('(',empty_STACK);
    Infix.push_back(')');
    for(int i=0;i<Infix.size();i++){
        if(Infix[i]=='(')
            Push_Element('(',empty_STACK);
        else if(Infix[i]=='+' || Infix[i]=='-') {
            while(empty_STACK->array[empty_STACK->top]=='*' || empty_STACK->array[empty_STACK->top]=='/' || empty_STACK->array[empty_STACK->top]=='+' || empty_STACK->array[empty_STACK->top]=='-') {
                char ch=Pop_Element(empty_STACK);
                Postfix.push_back(ch);
            }
            Push_Element(Infix[i],empty_STACK);
        }
        else if(Infix[i]=='*' || Infix[i]=='/') {
            while(empty_STACK->array[empty_STACK->top]=='*' || empty_STACK->array[empty_STACK->top]=='/') {
                char ch=Pop_Element(empty_STACK);
                Postfix.push_back(ch);
            }
            Push_Element(Infix[i],empty_STACK);
        }
        else if(Infix[i]==')'){
            while(empty_STACK->array[empty_STACK->top]!='('){
                char ch=Pop_Element(empty_STACK);
                Postfix.push_back(ch);
            }
            Pop_Element(empty_STACK);
        }
        else
            Postfix.push_back(Infix[i]);
    }
    return Postfix;
}

int main()
{
    std::string Infix_expression;
    std::cout<<"Enter Infix Expression : ";
    getline(std::cin,Infix_expression);
    STACK* Stack=create_STACK(Infix_expression.size());
    std::cout<<"Postfix Expression : "<<Infix_to_Postfix(Stack,Infix_expression);
    return 0;
}
