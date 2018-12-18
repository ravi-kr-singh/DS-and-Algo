#include <iostream>
#include <string>
using namespace std;

void Tower_Of_Hanoi(int,string,string,string);

int main()
{
    int num;
    cout<<"For how many number of rings you want instructions ? ";
    cin>>num;
    string A="Given Tower",B="Destiny Tower",C="Additional Tower";
    Tower_Of_Hanoi(num,A,B,C);
    return 0;
}

void Tower_Of_Hanoi(int n ,string given,string destiny,string auxiliary) {

    if(n==1) {
        cout<<"--> Take ring from "<<given<<" and place it in "<<destiny<<" .\n";
    }
    else {
            Tower_Of_Hanoi((n-1),given,auxiliary,destiny);
            cout<<"--> Take ring from "<<given<<" and place it in "<<destiny<<" .\n";
            Tower_Of_Hanoi((n-1),auxiliary,destiny,given);
    }


}
