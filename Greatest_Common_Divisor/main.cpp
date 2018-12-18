#include <iostream>

using namespace std;

int GCD(int,int);

int main()
{
    int num1,num2;
    cout << "Enter first number : ";
    cin>>num1;
    cout << "Enter second number : ";
    cin>>num2;
    cout<<"GCD : "<<GCD(num1,num2);
    return 0;
}

int GCD(int n1,int n2) {
    int ans;
    if(n1>n2) {
        if(n1%n2==0) {
            return n2;
        }
        else {
            ans=GCD((n1%n2),n2);
            return ans;
        }
    }
    else if (n2>n1){
        if(n2%n1==0) {
            return n1;
        }
        else {
            ans=GCD(n1,n2%n1);
            return ans;
        }
    }
    else {
        return n1;
    }

}

