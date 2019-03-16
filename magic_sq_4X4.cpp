/* Write a program to generate a magic square of order 4×4,
   filled with 16 consecutive numbers, where first number
   from 16 consecutive number is entered by user through keyboard. */

#include <iostream>
#include <iomanip>                   //for setw
#include <stdlib.h>                  //for abs
using namespace std;

void magic_sq(int num) {
    int m[4][4];

    for(int i=0;i<4;i++) {           //Constructing Magic square
        for(int j=0;j<4;j++) {
            if(i==j) {
                m[abs(3-i)][abs(3-j)]=num;
            }
            else if(i+j==3) {
                m[j][i]=num;
            }
            else {
                m[i][j]=num;
            }
            num++;
        }
    }
    for(int i=0;i<4;i++) {           //Displaying Magic square
        for(int j=0;j<4;j++) {
            cout<<setw(5)<<m[i][j];
        }
        cout<<endl;
    }

}

int main()
{
    int n;
    cout <<"Enter number : ";
    cin>>n;
    magic_sq(n);
    return 0;
}
