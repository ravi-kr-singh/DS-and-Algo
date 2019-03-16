#include <iostream>
#include <vector>
#include <stdlib.h>

void Merge_back(std::vector<int>& arr,std::vector<int>& left,std::vector<int>& right){
    int j=0,k=0,i=0;
    while(j<left.size() && k<right.size()){
			if(left[j]<right[k]){
				arr[i]=left[j];
				j++;
			}
			else{
				arr[i]=right[k];
				k++;
			}
			i++;
		}
		while(j<left.size()){
			arr[i]=left[j];
			i++;
			j++;
		}
		while(k<right.size()){
			arr[i]=right[k];
			i++;
			k++;
		}
}

void Merge_sort(std::vector<int>& arr){
	if(arr.size()>1){
		std::vector<int> left(arr.size()/2);
		std::vector<int> right(arr.size()-left.size());
		for(int i=0;i<arr.size();i++){
			if(i<left.size())
				left[i]=arr[i];
			else
				right[i-left.size()]=arr[i];
		}
		Merge_sort(left);
		Merge_sort(right);
		Merge_back(arr,left,right);
	}

}

int main(){
	system("cls");
	std::vector<int> my_arr={5,6,1,8,9,-4,7,56,102,-5,1,8,10};
	Merge_sort(my_arr);
	for(auto it=my_arr.begin();it!=my_arr.end();++it)
        std::cout<<*it<<" ";
	system("pause");
}
