#include <iostream>
#include <vector>
#include <stdlib.h>

void Bubble_sort(std::vector<int>& arr){
	for(int i=0;i<arr.size()-1;++i){
		int flag=-1;
		for(int k=0;k<arr.size()-1-i;++k){
			if(arr[k]>arr[k+1]){
				int temp=arr[k];
				arr[k]=arr[k+1];
				arr[k+1]=temp;
				flag=1;
			}
		}
		if(flag==-1)
			break;
	}
}

int main(){
	system("cls");
	std::vector<int> my_arr={1,-1,45,56,15,89,23,71};
	Bubble_sort(my_arr);
	for(std::vector<int>::iterator it=my_arr.begin();it!=my_arr.end();++it){
		std::cout<<*it<<" ";
	}
	system("pause");
}
