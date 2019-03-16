#include <iostream>
#include <vector>
#include <stdlib.h>

int partitioning(std::vector<int>& Array,int START,int END){
    int pivot_value=Array[END],pivot_index=START;
    for(int i=START;i<END;i++){
        if(Array[i]<=pivot_value){
            std::swap(Array[i],Array[pivot_index]);
            pivot_index++;
        }
    }
    std::swap(Array[pivot_index],Array[END]);
    return pivot_index;
}

void Quick_sort(std::vector<int>& arr,int START,int END){
	if(START<END){
		int pivot_Ind=partitioning(arr,START,END);
        Quick_sort(arr,START,pivot_Ind-1);
        Quick_sort(arr,pivot_Ind+1,END);

	}

}

int main() {
    system("cls");
    int n;
    std::cout<<"Enter number of elements : ";
    std::cin>>n;
	std::vector<int> my_arr(n);
	std::cout<<"Enter "<<n<<" elements for sorting : ";
	for(auto it=my_arr.begin();it!=my_arr.end();++it){
        std::cin>>*it;
	}
	int start=0,End=my_arr.size()-1;;
	Quick_sort(my_arr,start,End);
	for(auto it=my_arr.begin();it!=my_arr.end();++it)
		std::cout<<*it<<" ";
    system("pause");
	return 0;
}
