#include <iostream>
#include <string>
#include <vector>
void swap(char&,char&);
std::vector<std::string> Permutate(std::string,int,int);
bool Repetition_checker(std::vector<std::string>,std::string);


int main() {
	std::string given;
	std::cout<<"Enter String : ";
	std::getline(std::cin,given);
	std::vector<std::string> Storing_Permutaions=Permutate(given,0,(given.size()-1));
	for(int i=0;i<Storing_Permutaions.size();i++) {
        std::cout<<Storing_Permutaions[i]<<std::endl;
    }
	return 0;
}
std::vector<std::string> Permutate(std::string str,int start,int last) {
    std::vector<std::string> storing_strings;
	if(start==last){
       storing_strings.push_back(str);  //std::cout<<str<<std::endl;
	}
	else {
		for(int i=start;i<=last;i++) {
			swap(str[i],str[start]);
			std::vector<std::string> temp=Permutate(str,start+1,last);
			for(int i=0;i<temp.size();i++)
                if(Repetition_checker(storing_strings,temp[i])==true)
                    storing_strings.push_back(temp[i]);
			swap(str[i],str[start]);
		}
	}
	return storing_strings;
}
bool Repetition_checker(std::vector<std::string> My_Collection,std::string str) {
    for(int i=0;i<My_Collection.size();i++) {
        if(My_Collection[i]==str)
            return false;
    }
    return true;
}

void swap(char& a,char& b) {
	char temp=a;
	a=b;
	b=temp;
}
