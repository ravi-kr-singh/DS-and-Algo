#include <iostream>
#include <vector>


long long unsigned Fibonacci(long long unsigned n,std::vector<long long unsigned>& store){
	if(store[n]!=-1)
		return store[n];
	store[n]=Fibonacci(n-1,store)+Fibonacci(n-2,store);
	return store[n];
}


int main(){
	long long unsigned num;
	std::cout<<"Enter Number : ";
	std::cin>>num;
	std::vector<long long unsigned> memo(num+1,-1);
	memo[0]=0;
	memo[1]=1;
	std::cout<<Fibonacci(num,memo);

}
