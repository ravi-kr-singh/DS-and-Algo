#include <iostream>
#include <vector>
#include <stdlib.h>

void Insertion_sort(std::vector<int>& arr){
	for(int i=1;i<arr.size();i++){
		int temp=arr[i];
		int j=i-1;
		while(arr[j]>temp && j>=0){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;

	}
}

int main(){
    system("cls");
	std::vector<int> my_array={56,-5,12,3,4,1,0,78,102,-45,45,58,0,89,102,16,98};
	Insertion_sort(my_array);
	for(auto it=my_array.begin();it!=my_array.end();++it)
		std::cout<<*it<<" ";
    system("pause");
	return 0;
}
