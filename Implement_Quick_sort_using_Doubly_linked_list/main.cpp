#include <iostream>

struct node{
    int data;
    node* next;
    node* prev;
    node(int);
};
node* START=nullptr;
node::node(int a){
    data=a;
    next=nullptr;
    prev=nullptr;
}

void insert_node(int item){
    node* new_node= new node(item);
    if(START==nullptr){
        START=new_node;
    }
    else{
        node* temp=START;
        while(temp->next!=nullptr)
            temp=temp->next;
        temp->next=new_node;
        new_node->prev=temp;
    }
}
void show_list(){
    node* t=START;
    std::cout<<"List : ";
    while(t!=nullptr){
        std::cout<<t->data<<"  ";
        t=t->next;
    }
    std::cout<<"\n";
}
void swap(int* x,int* y) {
    int t=*x;
    *x=*y;
    *y=t;
}

node* dividing(node *l,node *h){
    node* i=l->prev;
    for (node* j=l;j!=h;j=j->next) {
        if (j->data<=h->data){
            i=(i==nullptr)?l:i->next;
            swap(&(i->data),&(j->data));
        }
    }
    i=(i==nullptr)?l:i->next;
    swap(&(i->data),&(h->data));
    return i;
}

void quick_sort(node* first,node* last){
    if (last!=nullptr && first!=last && first!=last->next){
        node *p = dividing(first,last);
        quick_sort(first,p->prev);
        quick_sort(p->next,last);
    }
}

int main()
{
    int n;
    std::cout<<"Enter number of elements : ";
    std::cin>>n;
    std::cout<<"Enter all "<<n<<" elements : ";
    for(int i=0;i<n;i++){
        int a;
        std::cin>>a;
        insert_node(a);
    }
    show_list();
    node* END=START;
    while(END->next!=nullptr){
        END=END->next;
    }
    quick_sort(START,END);
    std::cout<<"\nAfter Sorting, ";
    show_list();
    return 0;
}
