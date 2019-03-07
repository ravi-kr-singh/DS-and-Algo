#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    system("cls");
    int n,m,z;
    cout<<"For how many first natural numbers you wanna check Collatz Conjecture : ";
    cin>>z;
    cout<<"Checking Collatz Conjecture for first "<<z<<" natural numbers :-\n";
    for(n=1;n<z+1;n++) {
        m=n;
        cout<<endl<<n<<" : ";
        while(n!=1) {
            if(n%2==0) {
                n=n/2;
                if(n==1) {
                    cout<<n<<" .";
                }
                else {
                    cout<<n<<" , ";
                }
            }
            else {
               n=3*n+1;
               cout<<n<<" , ";
            }


        }
        n=m;
        cout<<endl;

    }
    cout<<endl;
    system("pause");
    return 0;
}
