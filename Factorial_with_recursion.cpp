#include <iostream>

using namespace std;
int Factorial (int);

int main()
{
    int num;
    cout << "Enter number : ";
    cin>>num;
    label:
    if(num<0) {
        cout<<"Invalid input!\nEnter positive number : ";
        cin>>num;
        goto label;
    }
    cout<<"Factorial of "<<num<<" is "<<Factorial(num)<<" .";
    return 0;
}
int Factorial (int n) {
    int ans=1;
    if(n>1) {
        ans=n*Factorial(n-1);
    }
    return ans;
}
