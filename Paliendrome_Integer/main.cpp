#include <iostream>

using namespace std;

int reverse_num(int a){
    int temp=a,rev=0,TotalDigits=0,t=1;
    while(temp!=0) {
        temp=temp/10;
        TotalDigits++;
    }
    temp=a;
    for(int i=1;i<TotalDigits;i++) {
        t=t*10;
    }
    for(int i=0;i<TotalDigits;i++) {
        rev=rev+((temp%10)*t);
        temp=temp/10;
        t=t/10;
    }
    return rev;
}

int main()
{
    int n;
    cout << "Enter Number : ";
    cin>>n;
    int rev=reverse_num(n);
    if(n==rev) {
        cout<<"Number you entered is Paliendrome";
    }
    else {
        cout<<"Number you entered is not Paliendrome as reversed number is "<<rev<<".";
    }
    return 0;
}
