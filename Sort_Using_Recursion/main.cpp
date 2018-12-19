#include <iostream>
void swap(int&,int&);
void Sort_using_Recursion(int* given,int Size) {
    int min=given[0],min_index=0;
    for(int i=1;i<Size;i++) {
        if(min>given[i]){
            min=given[i];
            min_index=i;
        }
    }
    if(min_index!=0)
        swap(given[0],given[min_index]);

    if(Size!=1)
        Sort_using_Recursion(given+1,Size-1);
}
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}


int main()
{
    int size_of_arr;
    std::cout << "Enter Size of Array : ";
    std::cin>>size_of_arr;
    int my_array[size_of_arr];
    std::cout<<"Enter Elements : ";
    for(int i=0;i<size_of_arr;i++)
        std::cin>>my_array[i];
    Sort_using_Recursion(my_array,size_of_arr);
    std::cout<<"After Sorting : ";
    for(int i=0;i<size_of_arr;i++)
        std::cout<<my_array[i]<<" ";
    return 0;
}
