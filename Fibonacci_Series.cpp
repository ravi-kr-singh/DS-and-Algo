#include <iostream>

using namespace std;
//void Fibonacci(int);
int Fibonacci(int);

int main()
{
    int n;
    cout << "Terms :  ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<Fibonacci(i)<<endl;
    }
    return 0;
}

/*void Fibonacci (int k) {                       //Without Recursion
    int a=0,b=1;
    cout<<a<<" , "<<b<<" , ";
    for(int i=2;i<k;i++) {
        int temp=a;
        a=b;
        b=temp+b;
        cout<<b<<" , ";
    }

}*/

int Fibonacci (int k) {
    if(k==1 || k==2){
        return 1;
    }
    return Fibonacci(k-1)+Fibonacci(k-2);
}
