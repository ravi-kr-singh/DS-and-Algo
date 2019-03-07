#include <iostream>
int GCD(int,int);
int GCD_of_N(int* numbers,int num){
	int ans=GCD(*numbers,*(numbers+1));
	for(int i=2;i<num;i++){
	ans=GCD(ans,(*(numbers+i)));
	}
	return ans;
}

int GCD(int a,int b) {
	if(a==b)
		return a;
	if(a%b==0)
		return b;
	if(b%a==0)
		return a;
	if(a>b)
		return GCD(a%b,b);
	else
		return GCD(a,b%a);
}

int main() {
	int num,inpit_checker=-1;
	std::cout<<"For how many numbers you want to find GCD : ";
	std::cin>>num;
	int Nums[num];
	std::cout<<"Enter all "<<num<<" numbers : ";
	for(int i=0;i<num;i++) {
		std::cin>>Nums[i];
	}
	std::cin>>inpit_checker;
	if(inpit_checker!=(-1))
        std::cout<<"Enter only "<<num<<" numbers.";
	std::cout<<"GCD : "<<GCD_of_N(Nums,num);
	return 0;
}
