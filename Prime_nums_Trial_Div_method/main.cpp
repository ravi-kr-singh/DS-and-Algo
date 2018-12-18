#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cout << "Enter number : ";
    cin>>n;
    for(int i=2;i<=n;i++) {
        if(i==2 || i==3 ) {
            cout<<i<<endl;
        }
        int t=sqrt(i);
        cout<<"       "<<t<<"........."<<endl;
        for(int j=2;j<=t;j++) {
            if(i%j==0)
                break;
            if(j==t)
                cout<<i<<endl;
        }

    }


    return 0;
}
