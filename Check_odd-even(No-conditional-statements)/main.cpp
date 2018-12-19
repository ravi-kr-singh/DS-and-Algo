#include <iostream>
#include <string>
std::string check_Odd_even(int n) {
    while(n%2==0)
        return "Even";
    return "Odd";
}


int main()
{
    int num;
    std::cout <<"Enter number : ";
    std::cin>>num;
    std::cout<<check_Odd_even(num);
    return 0;
}
