
#include <iostream>

#include <vector>

#include <stdlib.h>
void Selection_sort(std::vector<int>& int_arr){

	for(std::vector<int>::iterator it=int_arr.begin();it!=int_arr.end()-1;++it){

		std::vector<int>::iterator min=it;

		for(std::vector<int>::iterator it2=it+1;it2!=int_arr.end();++it2){
			if(*it2<*min){

                		min=it2;

			}

        	}

        	int temp=*it;

        	*it=*min;

        	*min=temp;

	}

}


int main()
{

	system("cls");
	std::vector<int> arr={2,7,4,1,5,3,12,-1,56,0,89,45,23};

	Selection_sort(arr);

	for(std::vector<int>::iterator it=arr.begin();it!=arr.end();++it){

        	std::cout<<*it<<" ";

	}

	system("pause");
}
